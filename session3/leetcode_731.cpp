class MyCalendarTwo {
public:
    vector<pair<int,int>> books;
    vector<pair<int,int>> overlaps;

    MyCalendarTwo() {
    }

    bool book(int start, int end) {

        for(auto &[s,e] : overlaps) {
            if(max(start,s) < min(end,e))
                return false;
        }

        for(auto &[s,e] : books) {

            int l = max(start,s);
            int r = min(end,e);

            if(l < r) {
                overlaps.push_back({l,r});
            }
        }

        books.push_back({start,end});

        return true;
    }
};
