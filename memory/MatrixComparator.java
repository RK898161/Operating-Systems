import java.util.Random;

public class MatrixComparator {
    public static void main(String[] args) {
        int dimension = Integer.parseInt(args[0]);        
        int[][] A = new int[dimension][dimension];
        int[][] B = new int[dimension][dimension];
        int[][] C1, C2;
        
        Random rn = new Random(42);
        for(int i = 0; i < dimension; i++)
            for(int j = 0; j < dimension; j++){           
                A[i][j] = rn.nextInt();
                B[i][j] = rn.nextInt();
            }
        // Mutliplying Two matrices
        C1 = matrix_mul_v1(A, B, dimension);
        C2 = matrix_mul_v2(A, B, dimension);
        //validate(C1, C2);
        // Displaying the result
        if (dimension < 16) {
            displayProduct(C1);
            displayProduct(C2);
        }
    }

    public static int[][] matrix_mul_v1(int[][] A, int[][] B, int dimension) {
        int[][] C = new int[dimension][dimension];      
        for(int i = 0; i < dimension; i++)
            for(int j = 0; j < dimension; j++)          
                C[i][j] = 0;
        long start = System.nanoTime();;
        for(int i = 0; i < dimension; i++)
            for(int j = 0; j < dimension; j++)
                for(int k = 0; k < dimension; k++)
                    C[i][j] += A[i][k] * B[k][j];
        long end = System.nanoTime();
          System.out.printf("v1 nanosecs:%d\n", end-start);   
        return C;
    }
    
    public static int[][] matrix_mul_v2(int[][] A, int[][] B, int dimension) {
        int[][] C = new int[dimension][dimension];      
        for(int i = 0; i < dimension; i++)
            for(int j = 0; j < dimension; j++)          
                C[i][j] = 0;
        long start = System.nanoTime();;
        for(int i = 0; i < dimension; i++)
            for(int j = 0; j < dimension; j++)
                for(int k = 0; k < dimension; k++)
                    C[i][k] += A[i][j] * B[j][k];
        long end = System.nanoTime();
          System.out.printf("v2 nanosecs:%d\n", end-start);   
        return C;
    }   

    public static void displayProduct(int[][] product) {
        System.out.println("Product of two matrices is: ");
        for(int[] row : product) {
            for (int column : row) {
                System.out.print(column + "    ");
            }
            System.out.println();
        }
    }
}