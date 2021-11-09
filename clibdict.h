namespace clib
{
    template <typename keyType, typename valueType>
    class dict
    {
    public:
        dict()
            {
                keyPtr = (keyType*)malloc(sizeof(keyType));
                valuePtr = (valueType*)malloc(sizeof(valueType));
            }
        ~dict(){/*destructor*/}
        size_t size() { return len; }

        int add(keyType key, valueType value)
        {
            if(hasKey(key)) return -1;
            ++len;
            keyPtr = (keyType*)realloc(keyPtr, sizeof(keyPtr)*len);
            valuePtr = (valueType*)realloc(valuePtr, sizeof(valuePtr)*len);
            keyPtr[len-1] = key;
            valuePtr[len-1] = value;
            return 0;
        }

        void getPtrs(keyType* &keys, valueType* &values) 
        {
            keys = keyPtr;
            values = valuePtr;
        }

        valueType operator[](keyType key)
        {
            for (size_t i = 0; i < len; i++)
            {
                if(keyPtr[i] == key) return valuePtr[i];
            }
            return (valueType)NULL;
        }

        int hasKey(keyType key)
        {
            for (size_t i = 0; i < len; i++)
            {
                if(keyPtr[i] == key) return 1;
            }
            return 0;
        }

    private:
        keyType* keyPtr;
        valueType* valuePtr;
        size_t len;
    };
    
}