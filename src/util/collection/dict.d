module util.collection.dict;

@safe @nogc pure nothrow:

import util.collection.arr : Arr, emptyArr, range, size;
import util.comparison : Comparison;
import util.opt : force, has, none, Opt, optOr, some;
import util.ptr : Ptr;

struct KeyValuePair(K, V) {
	K key;
	V value;
}

struct Dict(K, V, alias cmp) {
	private:
	Arr!(KeyValuePair!(K, V)) pairs;
}

immutable(size_t) dictSize(K, V, alias cmp)(ref immutable Dict!(K, V, cmp) a) {
	return size(a.pairs);
}

immutable(Opt!V) getAt(K, V, alias cmp)(immutable Dict!(K, V, cmp) d, immutable K key) {
	foreach (ref immutable KeyValuePair!(K, V) pair; d.pairs.range)
		if (cmp(pair.key, key) == Comparison.equal)
			return some!V(pair.value);
	return none!V;
}

immutable(Opt!(Ptr!V)) getAt_ptr(K, V, alias cmp)(ref immutable Dict!(K, V, cmp) d, immutable K key) {
	foreach (ref immutable KeyValuePair!(K, V) pair; d.pairs.range)
		if (cmp(pair.key, key) == Comparison.equal)
			return some!(Ptr!V)(immutable Ptr!V(&pair.value));
	return none!(Ptr!V);
}

immutable(Bool) hasKey(K, V, alias cmp)(ref immutable Dict!(K, V, cmp) d, immutable K key) {
	immutable Opt!V opt = getAt(d, key);
	return opt.has;
}

immutable(V) mustGetAt(K, V, alias cmp)(ref immutable Dict!(K, V, cmp) d, immutable K key) {
	immutable Opt!V opt = getAt(d, key);
	return opt.force;
}

immutable(Ptr!V) mustGetAt_ptr(K, V, alias cmp)(ref immutable Dict!(K, V, cmp) d, immutable K key) {
	immutable Opt!(Ptr!V) opt = d.getAt_ptr(key);
	return opt.force;
}
