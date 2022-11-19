package main

import (
	"fmt"
	"strconv"
	"sync"
	v1 "singleton/v1"
	v2 "singleton/v2"
	v3 "singleton/v3"
)

func demo_v1() {
	fmt.Println(">>> demo v1")
	count := 10
	var wg sync.WaitGroup
	wg.Add(count)

	for i := 0; i < count; i++ {
		go func(i int) {
			defer wg.Done()
			instance := v1.GetInstance("test" + strconv.FormatInt(int64(i), 10))
			fmt.Printf("%p: %s\n", instance, instance)
		}(i)
	}

	wg.Wait()
}

func demo_v2 () {
	fmt.Println(">>> demo v2")
	count := 10
	var wg sync.WaitGroup
	wg.Add(count)

	for i := 0; i < count; i++ {
		go func(i int) {
			defer wg.Done()
			instance := v2.GetInstance("test" + strconv.FormatInt(int64(i), 10))
			fmt.Printf("%p: %s\n", instance, instance)
		}(i)
	}

	wg.Wait()
}

func demo_v3 () {
	fmt.Println(">>> demo v3")
	count := 10
	var wg sync.WaitGroup
	wg.Add(count)

	for i := 0; i < count; i++ {
		go func(i int) {
			defer wg.Done()
			instance := v3.GetInstance("test" + strconv.FormatInt(int64(i), 10))
			fmt.Printf("%p: %s\n", instance, instance)
		}(i)
	}

	wg.Wait()
}

func main() {
	demo_v1()
	demo_v2()
	demo_v3()
}