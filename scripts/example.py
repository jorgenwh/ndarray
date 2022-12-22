import ndarray as nd

arr = nd.zeros(shape=(10, 200), dtype=nd.float32)

print(arr.dtype)
print(arr.shape)
print(arr.size)
print(arr.bytes)
print(arr)
print()

arr = nd.arange(start=0, end=20, step=1, dtype=nd.float32)

print(arr.dtype)
print(arr.shape)
print(arr.size)
print(arr.bytes)
print(arr)
