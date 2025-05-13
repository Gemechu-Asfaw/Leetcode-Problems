class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    int product = 1, zeroIndex = -1, count = 0;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        product = (product == 0) ? num : product*num;
        prefixProduct.push_back(product);
        if (num==0){
            zeroIndex = count;
        }
        count++;
    }
    
    int getProduct(int k) {
        if (count - k > zeroIndex){
            int divisor = 1;
            if (k==count){
                if (zeroIndex == -1){
                    return product;
                } else {
                    return 0;
                }
            } else {
                int divisor = prefixProduct[count-k-1]==0 ? 1 : prefixProduct[count-k-1];
                return prefixProduct[count-1]/divisor;
            }
        }
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */