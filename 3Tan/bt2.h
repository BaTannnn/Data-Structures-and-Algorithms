#pragma once
#include<iostream>
#include <math.h>
using namespace std;
struct Node{
	int info;
	Node *left;
	Node *right;
	Node(int inf = 0, Node *l = nullptr, Node *r = nullptr) {
		info = inf;
		left = l;
		right = r;
	}
};
struct BinaryTree {
	Node *root;
	BinaryTree() {
		root = nullptr;
	}
	void them_ds(Node*&p,int x) {
		if (p == nullptr)
			p = new Node(x);
		else {
			if (p->info == x)
				return;
			if (p->info > x)
				return them_ds(p->left, x);
			return them_ds(p->right, x);
		}
	}
	Node *timkiem(Node*&p, int x) {
		if (p == nullptr)
			return nullptr;
		else {
			if (p->info == x)
				return p;
			if (p->info > x)
				return timkiem(p->left, x);
			return timkiem(p->right, x);
		}
	}
	void timCucTrai(Node*deleteNode, Node*replaceNode) {
		if (replaceNode->left == nullptr) {
			deleteNode->info = replaceNode->info;
			deleteNode = replaceNode;
			replaceNode = replaceNode->right;
		}
		else {
			timCucTrai(deleteNode, replaceNode->left);
		}
	}
	int Xoa(Node*&p, int x) {
		if (p == nullptr)
			return 0;
		else if (p->info == x) {
			Node *tmp = p;
			if (p->left == nullptr)
				p = p->right;
			else if (p->right == nullptr)
				p = p->left;
			else {
				timCucTrai(tmp, p->right);
			}
			delete tmp;
			return 1;
		}
		else {
			if (p->info > x)
				return Xoa(p->left,x);
			return Xoa(p->right, x);
		}
	}
	void xuat(Node*&p) {
		cout << p->info << endl;
	}
	void duyetNLR(Node*&p) {
		if (p == nullptr)
			return;
		xuat(p);
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
	void duyetLNR(Node*&p) {
		if (p == nullptr)
			return;
		duyetLNR(p->left);
		xuat(p);
		duyetLNR(p->right);
	}
	void duyetLRN(Node*&p) {
		if (p == nullptr)
			return;
		duyetLRN(p->left);
		duyetLRN(p->right);
		xuat(p);
	}
	int dem(Node*&p) {
		if (p == nullptr)
			return 0;
		return 1 + dem(p->left) + dem(p->right);
	}
	int tongiatri(Node*&p) {
		if (p == nullptr)
			return 0;
		return p->info + tongiatri(p->right) + dem(p->right);
	}
	int avg() {
		return tongiatri(root) / dem(root);
	}
	int min(Node*&p) {
		if (p == nullptr)
			return p->info;
		return min(p->left);
	}
	int min(Node*&p) {
		if (p == nullptr)
			return p->info;
		return min(p->right);
	}
	bool songto(int x) {
		for (int i = 2; i < sqrt(x); i++) {

		}
	}
};