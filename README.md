# LBYARCH_x86-to-C-Interface-Programming
This program will compute the dot product of two scalar vectors. Its outputs are in **single-precision float**. The program contains both a **C kernel** and an **x86_64 Assembly kernel**. Both of the kernels will be tested **at least 30 times** to get the average time of their execution. This will be used for the analysis later on. The arrays are populated with random numbers. The size of array to be tested are **2<sup>20</sup>**, **2<sup>24</sup>**, and **2<sup>30</sup>**. The program will run on the **debug mode** of the Visual Studio and on the **release mode** of the Visual Studio.
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
| Cell 1 | Extra1 | Extra1 |
| Cell 2 | Extra2 | Extra1 |
| Cell 3 | Extra3 | Extra1 |
| Cell 4 | Extra4 | Extra1 |
| Cell 5 | Extra5 | Extra1 |

## Runtime in the x86_64 Assembly Kernel and Its Average on Debug Mode
The program is run for thirty (30) times to get the average runtime of the kernel.
|        |        |        |
|--------|--------|--------|
| Cell 1 | Extra1 | Extra1 |
| Cell 2 | Extra2 | Extra1 |
| Cell 3 | Extra3 | Extra1 |
| Cell 4 | Extra4 | Extra1 |
| Cell 5 | Extra5 | Extra1 |

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

