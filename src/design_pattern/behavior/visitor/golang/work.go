package visitor

func Work() {
	// 汇率 SDK 负责整合各种汇率
	// 但不关心访问者如何使用汇率
	RateSdk := NewSdk()

    // 不同的访问者使用汇率的方式不同
	laowang := &Visitor{&LaoWang{100.0}};
	RateSdk.Accept(laowang)

	joy := &Visitor{&Joy{100.0}};
	RateSdk.Accept(joy)
}
