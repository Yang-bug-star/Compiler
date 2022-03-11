struct Test_struct {
    int test_int;
    short test_short;
    long test_long;
    long long test_long_long;
    double test_double;
    float test_float;
    char test_char;
};

typedef int MYINT;
const int N = 3;
enum{LEFT, RIGHT};
/* 设置结构体 Test_struct 的成员
*
*\\
*/
void set(struct Test_struct* p, int in_int, short in_short, long in_long, long long in_long_long, double in_double, float in_float, char in_char) {
    p->test_int = in_int;
    p->test_short = in_short;
    p->test_long = in_long;
    p->test_long_long = in_long_long;
    p->test_double = in_double;
    p->test_float = in_float;
    p->test_char = in_char;
    return; 
}

int main() {
    struct Test_struct test;
    set(&test, 1, 2, 3e6, 3e6, 3.e05, 3.25e-2, 'a');
    test.test_int += 2;
    test.test_short -= 1;
    test.test_long /= 2;
    test.test_long_long >>= 1;
    test.test_double *= 2.5;
    test.test_int <<= 3;
    printf("%s", "\"Test\"\n");
    printf("char in test: %c, %ld byte\n", test.test_char, sizeof(test.test_char));
    
    int num[2] = {10, 30};
    for (auto i = 0; i < num[1]; ++i) {
        --num[0];
        if (!num[0]) break;
    }
    int a = num[0] + num[1];
    a ^= 0x12;
    a |= 0012;
    a &= 0X2;
    a %= 010;
    double b = 010.0;
    b = b - a;
    while (a--) continue;
    char c = u'\12';
    switch (c) {
        case 'a': printf("I'm""a\n");
        default: break;
    }
    if (a == 2) ;
    else if (a >= 3) ;
    else if (a <= -1) ;
    else if (a > 1);
    b = a != 5 ? 0 : 1; 
	@
    
}
