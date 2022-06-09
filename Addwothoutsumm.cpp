int Solution::addNumbers(int A, int B) {
    while(B){
        int carry= A&B;
        A = A^B;
        B = carry << 1;
    }
    return A;
}
/*  https://www.interviewbit.com/problems/addition-without-summation/  */