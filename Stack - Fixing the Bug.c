//top = 0 es incorrecto porque el primer elemento se insertaría en stack[0], haciendo imposible distinguir entre un stack vacío (top = 0) y un stack con un elemento (top = 0).
void push(int x) {
    if(top == MAX-1) return;
    stack[++top] = x;
}
