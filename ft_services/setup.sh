#!/bin/sh

minikube start --vm-driver=virtualbox --memory=3g 
eval $(minikube docker-env)
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
# kubectl create namespace kube-verify
docker build -t nginx-image srcs/nginx
docker build -t phpmyadmin-image srcs/phpmyadmin
docker build -t wordpress-image srcs/wordpress
docker build -t mysql-image srcs/mysql
docker build -t ftps-image srcs/ftps
docker build -t influxdb-image srcs/influxdb
kubectl apply -k .

minikube dashboard