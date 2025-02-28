package main

import "fmt"

func main() {
	// var s []int
	// fmt.Scan(s)
	// fmt.Print(s)
	fmt.Print(candy([]int{1,2,87,87,87,2,1}))

}

func candy(ratings []int) int {
	size := len(ratings)
	val := ratings[0]
	idxVal := 0
	for idx := 1; idx < size; idx++ {
		if ratings[idx] < val {
			idxVal = idx
			val = ratings[idx]
		}
	}

	noOfCandies := 1
	currCandies := 1
	for idx := idxVal - 1; idx >= 0; idx-- {
		if ratings[idx] > ratings[idx+1] {
			currCandies++
		} else if (idx-1 >= 0) && (ratings[idx-1] < ratings[idx]) {
			currCandies = 2
		} else {
			currCandies = 1
		}
		noOfCandies += currCandies
	}

	currCandies = 1
	for idx := idxVal + 1; idx < size; idx++ {
		if ratings[idx-1] < ratings[idx] {
			currCandies++
		} else if (idx+1 < size) && (ratings[idx] > ratings[idx+1]) {
			currCandies = 2
		} else {
currCandies = 1
		}
		noOfCandies += currCandies
	}
	return noOfCandies
}
