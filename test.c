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
	int j = 2;
    int num;
	int a[3];
	double b;
	char c;
	a[0] = 1;
    num=get_input();

    for(i = 1; i < num + 1; i++) print( factorial(i) + a[0] );

    return 0;
}
