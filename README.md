# NetDecoupled

For ShuffleNet, we take the one from the official and add our idea.

For other models, we take from pytorch model zoo and add our idea.

python main_s.py /home/nscc-gz-01/djs_FBIwarning/ImageNet/raw-data/ -a resnet50_s3_addchannel --lr 0.01 --workers=5 --gpu '1' --epochs 40 --batch-size 192
