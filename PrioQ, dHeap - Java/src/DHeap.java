// DHeap class
//
// CONSTRUCTION: with optional capacity (that defaults to 100)
//               or an array containing initial items
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// Comparable deleteMin( )--> Return and remove smallest item
// Comparable findMin( )  --> Return smallest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************
// Throws UnderflowException as appropriate

public class DHeap<AnyType extends Comparable<? super AnyType>>
{
	/**
	 * Construct the binary heap.
	 */
	public DHeap( )
	{

		this(2, DEFAULT_CAPACITY );
	}

	public DHeap(int d){

		this(d, DEFAULT_CAPACITY);
		if(d < 2){
			throw new IllegalArgumentException();
		}
	}

	/**
	 * Construct the binary heap.
	 * @param capacity the capacity of the binary heap.
	 */
	public DHeap(int d, int capacity )
	{

		this.d = d;
		currentSize = 0;
		
		array = (AnyType[]) new Comparable[ capacity + 1 ];
	}


	public int parentIndex(int child){
		if(child < 2){
			throw new IllegalArgumentException();
		}
		return (child - 2) / d + 1;
	}


	public int firstChildIndex(int parent){
		if(parent < 1){
			throw new IllegalArgumentException();
		}
		return (parent - 1) * d + 2;
	}
	

	public int size(){
		return currentSize;
	}


	public AnyType get(int i){
		return array[i];
	}
	
	/**
	 * Insert into the priority queue, maintaining heap order.
	 * Duplicates are allowed.
	 * @param x the item to insert.
	 */
	public void insert( AnyType x )
	{
		if( currentSize == array.length - 1 )
			enlargeArray( array.length * 2 + 1 );

		int hole = ++currentSize;
		for(array[0] = x ;hole > 1 &&  x.compareTo( array[parentIndex(hole)] ) < 0; hole = parentIndex(hole) )
			array[ hole ] = array[parentIndex(hole)];
		array[ hole ] = x;
	}


	private void enlargeArray( int newSize )
	{
		AnyType [] old = array;
		array = (AnyType []) new Comparable[ newSize ];
		for( int i = 0; i < old.length; i++ )
			array[ i ] = old[ i ];        
	}

	/**
	 * Find the smallest item in the priority queue.
	 * @return the smallest item, or throw an UnderflowException if empty.
	 */
	public AnyType findMin( )
	{
		if( isEmpty( ) )
			throw new UnderflowException( );
		return array[ 1 ];
	}

	/**
	 * Remove the smallest item from the priority queue.
	 * @return the smallest item, or throw an UnderflowException if empty.
	 */
	public AnyType deleteMin( )
	{
		if( isEmpty( ) )
			throw new UnderflowException( );

		AnyType minItem = findMin( );
		array[ 1 ] = array[ currentSize-- ];
		percolateDown( 1 );

		return minItem;
	}


	/**
	 * Test if the priority queue is logically empty.
	 * @return true if empty, false otherwise.
	 */
	public boolean isEmpty( )
	{
		return currentSize == 0;
	}

	/**
	 * Make the priority queue logically empty.
	 */
	public void makeEmpty( )
	{
		currentSize = 0;
	}

	private static final int DEFAULT_CAPACITY = 10;

	private int currentSize;      // Number of elements in heap
	private AnyType [ ] array; // The heap array
	private int d;

	/**
	 * Internal method to percolate down in the heap.
	 * @param hole the index at which the percolate begins.
	 */
	private void percolateDown( int hole )
	{
		int child;
		AnyType tmp = array[ hole ];

		for( ; firstChildIndex(hole) <= currentSize; hole = child )
		{
			child = firstChildIndex(hole);
			int tmpChild = child;
			for(int i = 0; i < d && tmpChild != size(); i++){
				if(array[tmpChild + 1].compareTo(array[child]) < 0){
					child = tmpChild + 1;
				}
				tmpChild++;
			}
			
			if( array[ child ].compareTo( tmp ) < 0 )
				array[ hole ] = array[ child ];
			else
				break;
		}
		array[ hole ] = tmp;
	}

	public static void main( String [ ] args )
	{
		int numItems = 10000;
		DHeap<Integer> h = new DHeap<>( );
		int i = 37;

		for( i = 37; i != 0; i = ( i + 37 ) % numItems )
			h.insert( i );
		for( i = 1; i < numItems; i++ )
			if( h.deleteMin( ) != i )
				System.out.println( "Oops! " + i );
	}
}

