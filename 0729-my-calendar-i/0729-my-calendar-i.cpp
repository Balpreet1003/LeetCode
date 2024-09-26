class MyCalendar {
    vector<pair<int, int>> v;
public:
    bool book(int s, int e) {
        for (auto& [i, j] : v)
            if (s < j && i < e) return false;
        v.push_back({s, e});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */