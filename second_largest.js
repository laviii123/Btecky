<script>

// Javascript program to find second largest
// element in an array

	// Function to print the second largest elements
	function print2largest(arr, arr_size) {
		let i, first, second;

		// There should be atleast two elements
		if (arr_size < 2) {
			document.write(" Invalid Input ");
			return;
		}

		// sort the array
		arr.sort();

		// start from second last element
		// as the largest element is at last
		for (i = arr_size - 2; i >= 0; i--) {
			// if the element is not
			// equal to largest element
			if (arr[i] != arr[arr_size - 1]) {
				document.write("The second largest element is " + arr[i]);
				return;
			}
		}

		document.write("There is no second largest element<br>");
	}

	// Driver program to test above function

	let arr= [ 12, 35, 1, 10, 34, 1 ];
	let n = arr.length;
	print2largest(arr, n);



</script>
