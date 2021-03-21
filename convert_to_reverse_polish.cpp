// does not work with -ve numbers
vector<variant<int, char>> convertToReversePolish(string in) {
  map<char, int> precedence{{'(', 0}, {'-', 1}, {'(', 0}
  stack<char> op;
  vector<variant<int, char>> r;
  for (int i = 0; i < in.size(); ++i) {
    char c = in[i];
    if (isdigit(c)) {
      int v = 0;
      while (i < in.size() && isdigit(in[i]))
        v = v * 10 + in[i] - '0';
      --i;
      r.push_back(v);
    }
    else if (c == '(')
      op.push(c);
    else if (c == ')') {
      while (!op.empty() && op.top != '(') {
        r.push_back(op.top());
        op.pop();
      }
      op.pop();
    }
    else {
      while (!op.empty() && precedence[op.top()] >= precedence[c]) {
        r.push_back(op.top());
        op.pop();
      }
      op.push(c);
    }
    
    return r;
}
