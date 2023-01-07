#include <iostream>
using namespace std;

class KeyExistsException : public exception {
  public:
    const char* what() const throw() {
      return "Key already exists.";
    }
};

class KeyNotFoundException : public exception {
  public:
    const char* what() const throw() {
      return "Key not found.";
    }
};

template<typename K, typename V>
class Map {
    private:
        K* keys;
        V* values;
        int size;

    public:
        Map() {
            size = 0;
            keys = nullptr;
            values = nullptr;
        };

        Map(const Map<K, V>& other) {
            size = other.size;
            keys = new K[size];
            values = new V[size];

            for (int i = 0; i < size; i++) {
                keys[i] = other.keys[i];
                values[i] = other.values[i];
            }
        };
        
        ~Map() {
            delete [] keys;
            delete [] values;
        };
        
        void add(K key, V value) {
            for (int i = 0; i < size; i++) {
                if (keys[i] == key) {
                    throw KeyExistsException();
                }
            }
            size++;

            if (keys == nullptr || values == nullptr) {
                keys = new K[size];
                values = new V[size];
                keys[size - 1] = key;
                values[size - 1] = value;
            }
            else {
                K* tempK = new K[size];
                V* tempV = new V[size];
                for (int i = 0; i < size - 1; i++) {
                    tempK[i] = keys[i];
                    tempV[i] = values[i];
                }
                tempK[size - 1] = key;
                tempV[size - 1] = value;
                delete [] keys;
                delete [] values;
                keys = tempK;
                values = tempV; 
            }
        };

        V* find(K key) {
            for (int i = 0; i < size; i++) {
                if (keys[i] == key) {
                    return &values[i];
                }
            }

            throw KeyNotFoundException();
        };

        Map<K, V>& operator=(const Map<K, V>& other) {
            if (this != &other) {
                delete [] keys;
                delete [] values;
                size = other.size;
                keys = new K[size];
                values = new V[size];
                for (int i = 0; i < size; i++) {
                    keys[i] = other.keys[i];
                    values[i] = other.values[i];
                }
            }
            return *this;
        };
        
        friend ostream& operator<<(ostream& os, const Map<K, V>& m) {
            for (int i = 0; i < m.size; i++) {
                os << m.keys[i] << ": " << m.values[i] << endl;
            }

            return os;
        };
};