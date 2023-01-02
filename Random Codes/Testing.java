public class Testing{
    public static void main(String[] args)
    {
        int miles = 5;
        System.out.printf("""
        The equivalent of %d miles is:
            %,d yards,
            %,d feet, or
            %,d inches
        """, miles, 1760*miles, 5280*miles, 12*5280*miles);
    }
}   