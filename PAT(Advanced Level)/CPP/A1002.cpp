/*
1002. A+B for Polynomials (25)
时间限制 400 ms
内存限制 65536 kB
代码长度限制 16000 B
This time, you are supposed to find A+B where A and B are two polynomials.

Input
Each input file contains one test case. Each case occupies 2 lines, and each line contains 
the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero 
terms in the polynomial(多项式), Ni and aNi (i=1, 2, ..., K) are the exponents(指数) and coefficients(系数), 
respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output
For each test case you should output the sum of A and B in one line, with the same format as 
the input. Notice that there must be NO extra space at the end of each line. Please be accurate 
to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output
3 2 1.5 1 2.9 0 3.2
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct poly{
    int exp;
    double coe;
};
int main(){
    int n1,n2;
    poly p1[11],p2[11],r[22];
    cin >> n1;
    for(int i = 0; i < n1; i++){
        cin >> p1[i].exp >> p1[i].coe;
    }
    cin >> n2;
    for(int  i = 0; i < n2; i++){
        cin >> p2[i].exp >> p2[i].coe;
    }

    int k = 0,i = 0,j = 0; 
    while(i < n1 && j < n2){
        if(p1[i].exp == p2[j].exp){
            r[k].exp = p1[i].exp;
            r[k].coe = p1[i++].coe + p2[j++].coe;
            if(r[k].coe == 0){
                continue;
            }
        }else if(p1[i].exp > p2[j].exp){
            r[k].coe = p1[i].coe;
            r[k].exp = p1[i++].exp;
        }else{
            r[k].coe = p2[j].coe;
            r[k].exp = p2[j++].exp;
        }
        k++;
    }
    while(i < n1){
        r[k].exp = p1[i].exp;
        r[k++].coe = p1[i++].coe;
    }
    while(j < n2){
        r[k].exp = p2[j].exp;
        r[k++].coe = p2[j++].coe;
    }

    if(k > 0){
        cout << k << ' ';
        for(int i = 0; i < k - 1; i++){
            printf("%d %.1f ",r[i].exp,r[i].coe);
        }
        printf("%d %.1f\n",r[k-1].exp,r[k-1].coe);
    }else{
        printf("0\n");
    }
    return 0;
}