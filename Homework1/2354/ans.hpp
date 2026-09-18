bool F(bool a, bool b) {
    /* TODO: You are expected not to use any bitwise operation except for operator==
     * example:
     * if(a == true)
     *    if(b == true)
     *       return true;
     */
    if(a == true and b == true){
        return false;
    }
    return true;
}
bool boolAnd(bool a, bool b) {
    /* TODO: You are expected not to use any bitwise operation except for
     * Function F
     */
    return F(F(a,b),F(a,b));
    
}
bool boolNot(bool a) {
    /* TODO: You are expected not to use any bitwise operation except for
     * Function F
     */
    return F(a,a);

}