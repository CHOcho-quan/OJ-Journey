class SnapshotArray {
public:
   SnapshotArray(int length) : cur_arr(length) {
    snap_count = 0;
    for(int i = 0; i < length; ++i){
        cur_arr[i][0] = 0;
    }
   }

    void set(int index, int val) {
        cur_arr[index][snap_count]=val;
    }
    
    int snap() {
        return snap_count++;
    }
    
    int get(int index, int snap_id) {
        auto iter = cur_arr[index].upper_bound(snap_id);
        return (--iter)->second;
    }

    vector<map<int,int>> cur_arr;
    int snap_count;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */