struct Trie {
  int next[50][10],fail[50];
  bool end[50];
  int L,root;
  int newNode() {
    for (int i = 0; i < 10; i++)
      next[L][i] = -1;
    end[L] = false;
    return L++;
  }
  void Init() {
    L = 0;
    root = newNode();
  }
  void Insert(char s[]) {
    int now = root;
    for (int i = 0; s[i] != 0; i++) {
      if (next[now][s[i]-'0'] == -1)
        next[now][s[i]-'0'] = newNode();
      now = next[now][s[i]-'0'];
    }
    end[now] = true;
  }
  void Build() {
    queue<int> Q;
    for (int i = 0; i < 10; i++)
      if (next[root][i] == -1)
        next[root][i] = root;
      else {
        fail[next[root][i]] = root;
        Q.push(next[root][i]);
      }
    while (!Q.empty()) {
      int now = Q.front();
      Q.pop();
      end[now] |= end[fail[now]];
      for (int i = 0; i < 10; i++)
        if (next[now][i] == -1)
          next[now][i] = next[fail[now]][i];
        else {
          fail[next[now][i]] = next[fail[now]][i];
          Q.push(next[now][i]);
        }
    }
  }
};
