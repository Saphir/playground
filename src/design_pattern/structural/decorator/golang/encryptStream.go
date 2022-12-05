package deco

import "fmt"

type encriptStream struct {
	stream iStream
}

func(es *encriptStream) Read() string {
	data := es.stream.Read()
	fmt.Println("Decrypting data")
	return data
}

func(es *encriptStream) Write(data string) {
	fmt.Println("Encrypting data")
	es.stream.Write(data)
}

func(es *encriptStream) Seek(position int, origin int) {
	es.stream.Seek(position, origin)
}
