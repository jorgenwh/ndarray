from enum import Enum

class dtype(Enum):
    int32 = 1
    float32 = 2

int32 = dtype.int32
float32 = dtype.float32

dtype_to_string = {
        int32: "int32",
        float32: "float32"
}
