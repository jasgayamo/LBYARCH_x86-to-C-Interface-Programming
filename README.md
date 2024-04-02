# LBYARCH_x86-to-C-Interface-Programming
This program will compute the dot product of two scalar vectors. Its outputs are in **single-precision float**. The program contains both a **C kernel** and an **x86_64 Assembly kernel**. Both of the kernels will be tested **at least 30 times** to get the average time of their execution. This will be used for the analysis later on. The arrays are populated with **random** float numbers. The size of array to be tested are **2<sup>20</sup>**, **2<sup>24</sup>**, and **2<sup>30</sup>**. The program will run on the **debug mode** of the Visual Studio and on the **release mode** of the Visual Studio.
## Screenshot of the C Output
This screenshot is taken from the program when n is equal to 2<sup>20</sup>.

![11 0 1](https://github.com/jasgayamo/LBYARCH_x86-to-C-Interface-Programming/assets/134362960/a8a5803d-5ac5-4249-bdc3-9877a51a9feb)

## Screenshot of the ASM Output and Its Sanity Check Test
This screenshot is taken from the program when n is equal to 2<sup>20</sup> and uses the output of the C kernel as the sanity check test.

![11 0 2](https://github.com/jasgayamo/LBYARCH_x86-to-C-Interface-Programming/assets/134362960/036a867d-f14d-4d44-a00f-8f08fff2e7a2)

## Runtime in the C Kernel and Its Average on Debug Mode
The program is run for thirty (30) times to get the average runtime of the kernel.
|        |        |        |
|--------|--------|--------|
| RUN| VECTOR SIZE| RUNTIME|
| 1  | 1073741824 | 3.030  |
| 2  | 1073741824 | 3.088  |
| 3  | 1073741824 | 3.083  |
| 4  | 1073741824 | 3.085  |
| 5  | 1073741824 | 3.088  |
| 6  | 1073741824 | 3.087  |
| 7  | 1073741824 | 3.088  |
| 8  | 1073741824 | 3.088  |
| 9  | 1073741824 | 3.083  |
| 10 | 1073741824 | 3.551  |
| 11 | 1073741824 | 3.167  |
| 12 | 1073741824 | 3.052  |
| 13 | 1073741824 | 3.089  |
| 14 | 1073741824 | 3.050  |
| 15 | 1073741824 | 3.081  |
| 16 | 1073741824 | 3.088  |
| 17 | 1073741824 | 3.086  |
| 18 | 1073741824 | 3.089  |
| 19 | 1073741824 | 3.089  |
| 20 | 1073741824 | 3.087  |
| 21 | 1073741824 | 3.088  |
| 22 | 1073741824 | 3.088  |
| 23 | 1073741824 | 3.086  |
| 24 | 1073741824 | 3.088  |
| 25 | 1073741824 | 3.088  |
| 26 | 1073741824 | 3.085  |
| 27 | 1073741824 | 3.088  |
| 28 | 1073741824 | 3.087  |
| 29 | 1073741824 | 3.088  |
| 30 | 1073741824 | 3.087  |


## Runtime in the x86_64 Assembly Kernel and Its Average on Debug Mode
The program is run for thirty (30) times to get the average runtime of the kernel.
|        |        |        |
|--------|--------|--------|
| RUN| VECTOR SIZE| RUNTIME|
| 1  | 16777216   | 0.057  |
| 2  | 1048576    | 0.000  |
| 3  | 1048576    | 0.001  |
| 4  | 1048576    | 0.001  |
| 5  | 1048576    | 0.001  |
| 6  | 1048576    | 0.001  |
| 7  | 1048576    | 0.001  |
| 8  | 1048576    | 0.001  |
| 9  | 1048576    | 0.001  |
| 10 | 1048576    | 0.001  |
| 11 | 1048576    | 0.001  |
| 12 | 1048576    | 0.001  |
| 13 | 1048576    | 0.000  |
| 14 | 1048576    | 0.001  |
| 15 | 1048576    | 0.001  |
| 16 | 1048576    | 0.001  |
| 17 | 1048576    | 0.001  |
| 18 | 1048576    | 0.001  |
| 19 | 1048576    | 0.001  |
| 20 | 1048576    | 0.001  |
| 21 | 1048576    | 0.001  |
| 22 | 1048576    | 0.001  |
| 23 | 1048576    | 0.001  |
| 24 | 1048576    | 0.001  |
| 25 | 1048576    | 0.001  |
| 26 | 1048576    | 0.001  |
| 27 | 1048576    | 0.001  |
| 28 | 1048576    | 0.001  |
| 29 | 1048576    | 0.001  |
| 30 | 1048576    | 0.001  |

## Runtime in the C Kernel and Its Average on Release Mode
The program is run for thirty (30) times to get the average runtime of the kernel.
|        |        |        |
|--------|--------|--------|
| Cell 1 | Extra1 | Extra1 |
| Cell 2 | Extra2 | Extra1 |
| Cell 3 | Extra3 | Extra1 |
| Cell 4 | Extra4 | Extra1 |
| Cell 5 | Extra5 | Extra1 |

## Runtime in the x86_64 Assembly Kernel and Its Average on Release Mode
The program is run for thirty (30) times to get the average runtime of the kernel.
|        |        |        |
|--------|--------|--------|
| Cell 1 | Extra1 | Extra1 |
| Cell 2 | Extra2 | Extra1 |
| Cell 3 | Extra3 | Extra1 |
| Cell 4 | Extra4 | Extra1 |
| Cell 5 | Extra5 | Extra1 |

## Analysis
### Debug Mode
When operating in debug mode, the code execution tends to be unoptimized and is likely
to incur longer execution times as compared to release mode, mainly due to the presence of
additional debugging information and less aggressive compiler optimizations. We conducted 30
runs in debug mode and recorded the execution times of the C and assembly implementations.
Despite the possibility of extended execution times due to debugging overhead, we observed
that the debug mode runs demonstrated consistent and stable behavior throughout.
### Release Mode
In contrast to debug mode, release mode compilation involves optimizing code execution
to maximize performance. We also conducted 30 runs of the program in release mode to
capture the execution times. The optimizations applied during release mode compilation
resulted in shorter execution times compared to debug mode. This is because, during release
mode compilation, the compiler eliminates overhead and unnecessary functions, which
enhances performance. In release mode, the code is optimized for performance by the compiler,
resulting in a notable improvement in execution times.
