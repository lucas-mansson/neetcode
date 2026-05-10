class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray(int capacity) {
        arr = new int[capacity];
        size = 0;
        this->capacity = capacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == capacity) {
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        int res = arr[size-1];
        arr[size-1] = 0;
        size--;
        return res;
    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for(int i = 0; i < size; i++){
            newArr[i] = arr[i];
        }
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
