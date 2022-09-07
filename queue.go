// linked list in go - for use specifically for advent of code 2020 day 22
package queue

import (
	"fmt"
	"strings"
)

// a single card in a deck
type node struct {
	card int
	next *node
}

// the deck of cards
type Queue struct {
	head   *node
	tail   *node
	length int
}

func Init() *queue {
	return &queue{
		head:   nil,
		tail:   nil,
		length: 0,
	}
}

func newNode(v int) *node {
	return &node{
		card: v,
	}
}

func (q *queue) ToString() string {
	var v []string
	tmp := q.head

	for tmp.next != nil {
		v = append(v, fmt.Sprintf("%d", tmp.card))
		tmp = tmp.next
	}

	v = append(v, fmt.Sprintf("%d", tmp.card))
	res := strings.Join(v, "")
	return res
}


// pull a card from the top of the card deck
func (q *queue) DrawCard() int {
	tmp := q.head
	if tmp == nil {
		return -1
	}
	q.head = tmp.next
	q.length--
	return tmp.card
}

// add a card to the bottom of the card deck
func (q *queue) AddCard(c int) {
	n := newNode(c)
	if q.head == nil {
		// empty list
		q.head = n
		q.tail = n
	} else {
		tmp := q.tail
		tmp.next = n
		q.tail = n
	}
	q.length++
}

// get the number of cards in a deck
func (q *queue) Len() int {
	return q.length
}

// print all the cards in a deck
func (q *queue) PrintList() {
	tmp := q.head
	if tmp == nil {
		return
	}

	for tmp.next != nil {
		fmt.Printf("%d ", tmp.card)
		tmp = tmp.next
	}
	fmt.Printf("%d\n", tmp.card)
}
