from .ndarray import ndarray
from .dtype import int16, int32, float32


def zeros(shape, dtype=float32):
    return ndarray(shape, dtype)

def arange(start, end, step=1, dtype=float32):
    return ndarray.arange(start=start, end=end, step=step, dtype=dtype)
