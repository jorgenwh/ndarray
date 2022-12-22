from .ndarray import ndarray
from .dtype import dtype

def zeros(shape, dtype=dtype.int32):
    return ndarray(shape)
