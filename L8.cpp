#include <iostream>
#include <string>

using namespace std;

struct obj {
        int id;
        int value;
};

struct set {
        int count;
        obj* objects;
};

set input() {
        set data;
        cin >> data.count;
        data.objects = new obj[data.count];
        for (int i = 0; i < data.count; i++) {
                cin >> data.objects[i].id;
                cin >> data.objects[i].value;
        }
        return data;
}

void erase(set data) {
        delete[] data.objects;
}

void mode0(set data) {
        int max = 0;
        for (int i = 0; i < data.count; i++) {
                if (data.objects[i].value >= max) {
                        max = data.objects[i].value;
                }
        }
        cout << max;
}

void mode1(set data, int arg) {
        for (int i = 0; i < data.count; i++) {
                if (data.objects[i].value==arg) {
                        cout << data.objects[i].id << " ";
                }
        }
}

void mode2(set data) {
        for (int i = data.count-1; i >= 0; i--) {
                cout << data.objects[i].id << " " << data.objects[i].value << "  ";
        }
}

void mode3(set data, int lbound, int ubound) {
        int found = 0;
        for (int i = 0; i < data.count; i++) {
                if (data.objects[i].value >= lbound && data.objects[i].value <= ubound) {
                        found++;
                }
        }
        cout << found << " / " << data.count << "  ";
}

int main() {
        int mode, v, lbound, ubound;
        cin >> mode;
        set bounds;
        if (mode == 1) {
                cin >> v;
        }
        else if (mode == 3) {
                cin >> lbound;
                cin >> ubound;
        }
        else if (mode == 4) {
                cin >> bounds.count;
                bounds.objects = new obj[bounds.count];
                for (int a = 0; a < bounds.count; a++) {
                        cin >> bounds.objects[a].id;
                        cin >> bounds.objects[a].value;
                }
        }
        set data = input();
        if (mode == 0) {
                mode0(data);
        }
        else if (mode == 1) {
                mode1(data,v);
        }
        else if (mode == 2) {
                mode2(data);
        }
        else if (mode == 3) {
                mode3(data, lbound, ubound);
        }
        else if (mode == 4) {
                for (int b = 0; b < bounds.count; b++) {
                        mode3(data, bounds.objects[b].id, bounds.objects[b].value);
                }
                erase(bounds);
        }
        erase(data);
        return 0;
}
