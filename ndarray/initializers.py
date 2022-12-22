from .ndarray import ndarray
from .dtype import int32

def zeros(shape, dtype=int32):
    return ndarray(shape, dtype)
