## Macro
### 1. string
`#`：将宏参数转换为字符串  
`##`: 把参数 x##y 合并成一个符号, 而不是字符串
```C++
#define T(x) #x
int temp = 200;
std::cout << T(temp) << std::endl;
// 输出是 temp

#define T2(x, y) x##y

int ab = 200;
std::cout << T2(a, b) << std::endl;
// 输出是 200

```