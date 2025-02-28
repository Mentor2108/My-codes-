import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
 
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
        }
    }

    public void insert(int value) {
        if (cache.size() == cacheSize) { // remove least frequently used
            int lfuKey = findLFU();
            System.out.println("Cache block " + lfuKey + " is popped");
            cache.remove(lfuKey);
        }
 
        FrequencyVal newFrequencyVal = new FrequencyVal(value, 1);
        cache.put(value, newFrequencyVal);
        System.out.println("Cache block " + value + " is inserted");
    }
 
    public void refer(int value)
    {
        if (!cache.containsKey(value)) {
            insert(value);
        }
        else {
            increment(value);
        }
    }
 
    public int findLFU() {
        int lfuKey = 0;
        int minFrequency = Integer.MAX_VALUE;
        for (Map.Entry<Integer, FrequencyVal> entry :
             cache.entrySet()) {
            if (entry.getValue().frequency < minFrequency) {
                minFrequency = entry.getValue().frequency;
                lfuKey = entry.getKey();
            }
        }
        return lfuKey;
    }
}
 
public class Main {
    public static void main(String[] args) {
        LFU lfuCache = new LFU(2);
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        
        List list = new ArrayList<>();
        for (int i = 0; i<n; i++) {
            list.add(scanner.nextInt());
            lfuCache.refer((int)list.get(i));
        }
    }
}