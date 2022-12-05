package deco

import "fmt"

type compressStream struct {
	stream iStream
}

func(cs *compressStream) Read() string {
	data := cs.stream.Read()
	fmt.Println("Decompressing data")
	return data
}

func(cs *compressStream) Write(data string) {
	fmt.Println("Compressing data")
	cs.stream.Write(data)
}

func(cs *compressStream) Seek(position int, origin int) {
	cs.stream.Seek(position, origin)
}
