struct Test_struct {
    int test_int;
    short test_short;
};

typedef int MYINT;
const int N = 3;
enum{LEFT, RIGHT};
/* 设置结构体 Test_struct 的成员
*
*\\
*/
enum{i} yinzi;
void set(struct Test_struct* p, int in_int, short in_short) {
    p->test_int = in_int;
    p->test_short = in_short;
    return; 
}
int m(){}

int main() {
	int a = (2*2, 3*3);
    struct Test_struct test;
    set(&test, 1, 2);
    test.test_int += 2;
    test.test_short -= 1;
    printf("%s", "\"Test\"\n");
   
	int num[2 = {10, 30};
    for (auto i = 0; i < num[1]; ++i) {
        --num[0];
        if (!num[0]) break;
    }
    a = num[0] + num[1];
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
    m();

