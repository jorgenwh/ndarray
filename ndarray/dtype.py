from enum import IntEnum

class dtype(IntEnum):
    int16 = 0
    int32 = 1
    float32 = 2

int16 = dtype.int16
int32 = dtype.int32
float32 = dtype.float32

dtype_to_string = {
        int16: "int16",
        int32: "int32",
        float32: "float32"
}
