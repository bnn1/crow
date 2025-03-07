module util.col.multiDict;

@safe @nogc pure nothrow:

import util.alloc.alloc : Alloc;
import util.col.arr : emptyArr, ptrAt;
import util.col.dict : dictEach, Dict, getAt, KeyValuePair;
import util.col.mutArr : moveToArr, MutArr, push;
import util.col.mutDict : getOrAdd, mapToDict, MutDict;
import util.opt : force, has, Opt;
import util.ptr : Ptr;
import util.sym : hashSym, Sym, symEq;

private struct MultiDict(K, V, alias equal, alias hash) {
	private:
	immutable Dict!(K, V[], equal, hash) inner;
}

alias SymMultiDict(V) =
	MultiDict!(Sym, V, symEq, hashSym);

@trusted void multiDictEach(K, V, alias equal, alias hash)(
	ref immutable MultiDict!(K, V, equal, hash) a,
	scope void delegate(immutable K, immutable V[]) @safe @nogc pure nothrow cb,
) {
	dictEach!(K, V[], equal, hash)(a.inner, (immutable K key, ref immutable V[] value) {
		cb(key, value);
	});
}

@trusted immutable(V[]) multiDictGetAt(K, V, alias equal, alias hash)(
	ref immutable MultiDict!(K, V, equal, hash) a,
	ref immutable K key,
) {
	immutable Opt!(V[]) res = getAt(a.inner, key);
	return has(res) ? force(res) : emptyArr!V;
}

@trusted immutable(MultiDict!(K, V, equal, hash)) buildMultiDict(K, V, alias equal, alias hash, T)(
	ref Alloc alloc,
	immutable T[] inputs,
	scope immutable(KeyValuePair!(K, V)) delegate(immutable size_t, immutable Ptr!T) @safe @nogc pure nothrow getPair,
) {
	MutDict!(immutable K, MutArr!(immutable V), equal, hash) builder;
	foreach (immutable size_t i; 0 .. inputs.length) {
		immutable KeyValuePair!(K, V) pair = getPair(i, ptrAt(inputs, i));
		push(alloc, getOrAdd(alloc, builder, pair.key, () => MutArr!(immutable V)()), pair.value);
	}
	return immutable MultiDict!(K, V, equal, hash)(
		mapToDict!(K, V[], MutArr!(immutable V), equal, hash)(alloc, builder, (ref MutArr!(immutable V) arr) =>
			moveToArr!V(alloc, arr)));
}
