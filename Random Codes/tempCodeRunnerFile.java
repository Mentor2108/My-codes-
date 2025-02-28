import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
 
class FrequencyVal {
    int value, frequency;
 
    public FrequencyVal(int value, int frequency) {
        this.value = value;
        this.frequency = frequency;
    }
}
 
class LFU {
    int cacheSize;
    Map<Integer, FrequencyVal> cache;
 
    public LFU(int cacheSize) {
        this.cacheSize = cacheSize;
        this.cache = new HashMap<Integer, FrequencyVal>();
    }
 
    public void increment(int value) {
        if (cache.containsKey(value)) {
            cache.get(value).frequency += 1;