module util.collection.mutIndexDict;

@safe @nogc pure nothrow:

import util.collection.arr : Arr, at, setAt;
import util.collection.arrUtil : fillArr_mut;
import util.collection.mutDict : ValueAndDidAdd;
import util.bools : False, True;
import util.memory : initMemory, overwriteMemory;
import util.opt : force, has, noneMut, Opt, someMut;

struct MutIndexDict(K, V) {
	private:
	Arr!(Opt!V) values_;
}

MutIndexDict!(K, V) newMutIndexDict(K, V, Alloc)(ref Alloc alloc, immutable size_t size) {
	return MutIndexDict!(K, V)(fillArr_mut!(Opt!V)(alloc, size, (immutable size_t) =>
		noneMut!V));
}

ref const(V) mustGetAt(K, V)(ref const MutIndexDict!(K, V) a, immutable K key) {
	return force(at(a.values_, key.index));
}

immutable(ValueAndDidAdd) addIfNotPresent(K, V)(
	ref MutIndexDict!(K, V) a,
	immutable K key,
	scope V delegate() @safe @nogc pure nothrow getValue,
) {
	immutable Bool present = has(at(a.values_, key.index));
	if (!present)
		setAt(a.values_, key.index, some!V(getValue()));
	return not(present);
}

void updateOrSet(K, V)(
	ref MutIndexDict!(K, V) a,
	immutable K key,
	scope void delegate(ref V) @safe @nogc pure nothrow cbUpdate,
	scope V delegate() @safe @nogc pure nothrow cbSet,
) {
	immutable size_t index = key.index;
	if (has(at(a.values_, index)))
		cbUpdate(force(at(a.values_, index)));
	else
		setAt!(Opt!V)(a.values_, index, someMut(cbSet()));
}

immutable(ValueAndDidAdd!V) getOrAddAndDidAdd(K, V)(
	ref MutIndexDict!(K, V) a,
	immutable K key,
	scope V delegate() @safe @nogc pure nothrow getValue,
) {
	immutable size_t index = key.index;
	if (has(at(a.values_, index)))
		return immutable ValueAndDidAdd!V(force(at(a.values_, index)), False);
	else {
		immutable V value = getValue();
		setAt(a.values_, index, someMut!V(value));
		return immutable ValueAndDidAdd!V(value, True);
	}
}
