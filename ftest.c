void main(int *a, int n) {
    int i;
    for(i = 0; i != n-1; i++)
        *(a+i) = *(a+(i+1));
      }
      
      
/*void main(int *a, int n) {
    int *p;
    for(p = a; p != a+(n-1); p++)
        *p = *(p+1);
      }*/
