void print_a(int a);

int factorial(int i) {
    if (i <= 1) {
        return 1;
    }
    else{
        return i * factorial(i - 1);
    }
}



int main() {
    int i;
    int times;
	int a[3] = {0,1, 2};
	double b;
	a[0] = 1;
    times=read();

    for(i = 1; i < times + 1; i++) print( factorial(i) + a[0] );
	
	print(i);
	print(i << 1);
	print(i >> 1);
	print(i | 1);
	print(i & 1);
	print(i ^ 1);
	print(i < 1 && i > 2);
	print(i < 1 || i > 2);
	print(a[0] - i);
	print(a[0] * i);
	print(a[0] / i);
	print(a[0] % i);
	print(!i);
	print(~i);
	print(i <= 2);
	print(i > 2 );
	print(i >= 2);
	print(i == 2);
	print(i != 2);
	i += 2;
	print(i);
	i -= 2;
	print(i);
	i *= 2;
	print(i);
	i /= 2;
	print(i);
	i %= 2;
	print(i);
	i &= 2;
	print(i);
	i |= 2;
	print(i);
	i ^= 2;
	print(i);
	i = 2 > 0 ? 1 : 0;
	print(i);
	i--;
	print(i);

	while (i < 0) {
		++i;
		if (i >= 2) break;
	}
	

    return 0;
}

void print_a(int a) {
	print(a);
}

