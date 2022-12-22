from .dtype import int16, int32, float32
from .dtype import dtype_to_string

from ndarray_backend import ndarray_int16 as __int16_array
from ndarray_backend import ndarray_int32 as __int32_array
from ndarray_backend import ndarray_float32 as __float32_array


_array_types = {
        int16: __int16_array,
        int32: __int32_array,
        float32: __float32_array
}


class ndarray():
    def __init__(self, shape, dtype=float32):
        self._shape = shape
        self._dtype = dtype

        if isinstance(self._shape, int):
            self._shape = (self._shape,)
        
        self._backend = _array_types[self._dtype](self._shape, int(self._dtype))

    @classmethod
    def arange(cls, start, end, step, dtype):
        size = ((end - start) + step - 1) // step
        arr = cls(shape=(size,), dtype=dtype)
        arr._backend.apply_arange(start, end, step)
        return arr

    @property
    def dtype(self):
        return self._dtype

    @property
    def shape(self):
        return self._shape

    @property
    def size(self):
        return self._backend.size

    @property
    def bytes(self):
        return self._backend.bytes

    def __str__(self):
        return self.__repr__()

    def __repr__(self):
        return f"ndarray({self._backend.to_string()}, dtype={dtype_to_string[self._dtype]})"


