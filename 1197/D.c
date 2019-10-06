#include<stdio.h>
#include<stdlib.h>

int main(){
    long long n, m, k;
    long long *a;

    long long prev_idx = 0;
    long long current_sum = 0;
    long long current_max = 0;

    scanf("%I64d %I64d %I64d", &n, &m, &k);

    a = (long long *)malloc(sizeof(long long) * n);

    for(long long i = 0; i < n; i++)
        scanf("%I64d", a + i);

    for(long long i = 0; i < n; i++){
        long long new_max;

        current_sum += a[i];
        if(current_sum <= 0){
            current_sum = 0;
            prev_idx = i + 1;
            continue;
        }

        long long child = i - prev_idx + 1;
        long long division = child / m;
        long long has_reserve = (child > (division * m));

        if(!has_reserve){
            if(a[prev_idx] < a[idx]){
                current_sum -= a[prev_idx];
                current_sum += a[idx];
                prev_idx += 1;
            }
        }

        new_max = current_sum - (k * (division + has_reserve));


}
