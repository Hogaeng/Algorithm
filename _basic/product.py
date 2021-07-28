import itertools as it
pp=it.product("01","01")
for p in pp:
    print(p)
print()
pp=it.product("01",repeat=2)
for p in pp:
    print(p)
print()
pp=it.combinations_with_replacement("01",2)
for p in pp:
    print(p)
print()