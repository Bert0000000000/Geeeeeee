//
//  main.swift
//  设计模式
//
//  Created by Bert on 2/3/15.
//  Copyright (c) 2015 Bert. All rights reserved.
//

import Foundation
//简单工厂模式

var factory = Factory()
var A = factory.Create("A")
A.TurnOn()
A.TurnOff()

//工厂模式
var factory1 = ContreteFactory1()
var factory2 = ContreteFactory2()

var model_a = factory1.createModel()
var model_b = factory2.createModel()

model_a.print_name("A")
model_b.print_name("B")

//抽象工厂
var afactory = ConcreteFactoryA()
var e = Environment(factory: afactory);
e.showProduct()

var bfactory = ConcreteFactoryB()
var e2 = Environment(factory: bfactory)
e2.showProduct()
