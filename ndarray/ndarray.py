from .dtype import dtype

from ndarray_backend import ndarray as __ndarray

class ndarray(__ndarray):
    def __init__(self, shape):
        if isinstance(shape, int):
            shape = (shape,)
        super().__init__(shape)

    def __str__(self):
        return self.__repr__()

    def __repr__(self):
        return self.to_string()
