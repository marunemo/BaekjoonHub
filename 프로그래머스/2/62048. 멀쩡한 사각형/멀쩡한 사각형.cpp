using namespace std;

int GCD(int a, int b) {
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

long long solution(int w,int h) {
    long long answer = (long long)w * h;
    long long abandon = 0;
    long long gcd = GCD(w, h);
    // 기울기: first / second
    long long gradient[2] = {w / gcd, h / gcd};
    long long block[2] = {1, 1};
    long long grad_num, block_num;
    
    while(block[0] <= w && block[1] <= h) {
        grad_num = gradient[0] * block[1];
        block_num = block[0] * gradient[1];
        
        if(grad_num <= block_num)
            block[1]++;
        if(grad_num >= block_num)
            block[0]++;
        abandon++;
    }
    
    return answer - abandon;
}