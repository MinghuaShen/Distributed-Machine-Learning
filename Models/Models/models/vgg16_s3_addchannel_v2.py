import os
import math
import torch
import torch.nn as nn
import torch.utils.model_zoo as model_zoo

__all__ = [
    'VGG', 'vgg11', 'vgg11_bn', 'vgg13', 'vgg13_bn', 'vgg16', 'vgg16_bn', 'vgg19_bn', 'vgg19'
]

# you need to download the models to ~/.torch/models
# model_urls = {
#     'vgg11': 'https://download.pytorch.org/models/vgg11-bbd30ac9.pth',
#     'vgg13': 'https://download.pytorch.org/models/vgg13-c768596a.pth',
#     'vgg16': 'https://download.pytorch.org/models/vgg16-397923af.pth',
#     'vgg19': 'https://download.pytorch.org/models/vgg19-dcbb9e9d.pth',
#     'vgg11_bn': 'https://download.pytorch.org/models/vgg11_bn-6002323d.pth',
#     'vgg13_bn': 'https://download.pytorch.org/models/vgg13_bn-abd245e5.pth',
#     'vgg16_bn': 'https://download.pytorch.org/models/vgg16_bn-6c64b313.pth',
#     'vgg19_bn': 'https://download.pytorch.org/models/vgg19_bn-c79401a0.pth',
# }
models_dir = os.path.expanduser('~/.torch/models')
model_name = {
    'vgg11': 'vgg11-bbd30ac9.pth',
    'vgg11_bn': 'vgg11_bn-6002323d.pth',
    'vgg13': 'vgg13-c768596a.pth',
    'vgg13_bn': 'vgg13_bn-abd245e5.pth',
    'vgg16': 'vgg16-397923af.pth',
    'vgg16_bn': 'vgg16_bn-6c64b313.pth',
    'vgg19': 'vgg19-dcbb9e9d.pth',
    'vgg19_bn': 'vgg19_bn-c79401a0.pth',
}


class VGG(nn.Module):

    def __init__(self, num_classes=1000, init_weights=True):
        super(VGG, self).__init__()
        num_groups = 4
        self.block0 = nn.Sequential(
            
            nn.Conv2d(3, 96, kernel_size=3, padding=1),
            nn.BatchNorm2d(96), 
            nn.ReLU(inplace=True),
            
            nn.Conv2d(96, 112, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(112), 
            nn.ReLU(inplace=True),
            
            nn.MaxPool2d(kernel_size=2, stride=2),
            
            nn.Conv2d(112, 224, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(224), 
            nn.ReLU(inplace=True),
            
            nn.Conv2d(224, 224, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(224), 
            nn.ReLU(inplace=True),
            
            nn.MaxPool2d(kernel_size=2, stride=2),
            
            nn.Conv2d(224, 448, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(448), 
            nn.ReLU(inplace=True)
        )
            
        self.block1 = nn.Sequential(
            nn.Conv2d(448, 448, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(448), 
            nn.ReLU(inplace=True),
            
            nn.Conv2d(448, 448, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(448), 
            nn.ReLU(inplace=True),
            
            nn.MaxPool2d(kernel_size=2, stride=2),
            
            nn.Conv2d(448, 896, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(896), 
            nn.ReLU(inplace=True),
            
            nn.Conv2d(896, 896, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(896), 
            nn.ReLU(inplace=True)
            
        )
        self.block2 = nn.Sequential(
            nn.Conv2d(896, 896, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(896), 
            nn.ReLU(inplace=True),
            
            nn.MaxPool2d(kernel_size=2, stride=2),
            
            nn.Conv2d(896, 896, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(896), 
            nn.ReLU(inplace=True),
            
            nn.Conv2d(896, 896, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(896), 
            nn.ReLU(inplace=True),            
            
            
            nn.Conv2d(896, 512, kernel_size=3, padding=1, groups=4),
            nn.BatchNorm2d(512), 
            nn.ReLU(inplace=True),
            
            nn.MaxPool2d(kernel_size=2, stride=2)
        )
        self.classifier = nn.Sequential(
            nn.Linear(512 * 7 * 7, 4096),
            nn.ReLU(inplace=True),
            nn.Dropout(),
            nn.Linear(4096, 4096),
            nn.ReLU(inplace=True),
            nn.Dropout(),
            nn.Linear(4096, num_classes)
        )
        if init_weights:
            self._initialize_weights()

    def forward(self, x):
        x = self.block0(x)
        x = self.channel_shuffle(x)
        x = self.block1(x)
        x = self.channel_shuffle(x)
        x = self.block2(x)
        x = x.view(x.size(0), -1)
        x = self.classifier(x)
        return x
    
    def channel_shuffle(self, x):
        num_group = 4
        batchsize, num_channels, height, width = x.data.size()
        assert num_channels % num_group == 0
        group_channels = num_channels // num_group
        
        x = x.reshape(batchsize, group_channels, num_group, height, width)
        x = x.permute(0, 2, 1, 3, 4)
        x = x.reshape(batchsize, num_channels, height, width)
        return x

    def _initialize_weights(self):
        for m in self.modules():
            if isinstance(m, nn.Conv2d):
                n = m.kernel_size[0] * m.kernel_size[1] * m.out_channels
                m.weight.data.normal_(0, math.sqrt(2. / n))
                if m.bias is not None:
                    m.bias.data.zero_()
            elif isinstance(m, nn.BatchNorm2d):
                m.weight.data.fill_(1)
                m.bias.data.zero_()
            elif isinstance(m, nn.Linear):
                m.weight.data.normal_(0, 0.01)
                m.bias.data.zero_()


def make_layers(cfg, batch_norm=False):
    layers = []
    in_channels = 3
    
    conv2d = nn.Conv2d(in_channels, 96, kernel_size=3, padding=1)
    layers += [conv2d, nn.ReLU(inplace=True)]
    
    in_channels = 96
    for v in cfg:
        if v == 'M':
            layers += [nn.MaxPool2d(kernel_size=2, stride=2)]
        else:
            conv2d = nn.Conv2d(in_channels, v, kernel_size=3, padding=1, groups=4)
            if batch_norm:
                layers += [conv2d, nn.BatchNorm2d(v), nn.ReLU(inplace=True)]
            else:
                layers += [conv2d, nn.ReLU(inplace=True)]
            in_channels = v
    return nn.Sequential(*layers)


cfg = {
    'A': [64, 'M', 128, 'M', 256, 256, 'M', 512, 512, 'M', 512, 512, 'M'],
    'B': [64, 64, 'M', 128, 128, 'M', 256, 256, 'M', 512, 512, 'M', 512, 512, 'M'],
    'D': [64, 64, 'M', 128, 128, 'M', 256, 256, 256, 'M', 512, 512, 512, 'M', 512, 512, 512, 'M'],
    'E': [64, 64, 'M', 128, 128, 'M', 256, 256, 256, 256, 'M', 512, 512, 512, 512, 'M', 512, 512, 512, 512, 'M'],
    'F': [96, 'M', 192, 192, 'M', 384, 384, 384, 'M', 768, 768, 768, 'M', 768, 768, 768, 'M'],
}



def vgg16_bn_s3_addchannel_v2(pretrained=False, **kwargs):
    """VGG 16-layer model (configuration "D") with batch normalization

    Args:
        pretrained (bool): If True, returns a model pre-trained on ImageNet
    """
    if pretrained:
        kwargs['init_weights'] = False
    model = VGG(**kwargs)
    if pretrained:
        model.load_state_dict(torch.load(os.path.join(models_dir, model_name['vgg16_bn'])))
    return model


def vgg19(pretrained=False, **kwargs):
    """VGG 19-layer model (configuration "E")

    Args:
        pretrained (bool): If True, returns a model pre-trained on ImageNet
    """
    if pretrained:
        kwargs['init_weights'] = False
    model = VGG(make_layers(cfg['E']), **kwargs)
    if pretrained:
        model.load_state_dict(torch.load(os.path.join(models_dir, model_name['vgg19'])))
    return model


def vgg19_bn(pretrained=False, **kwargs):
    """VGG 19-layer model (configuration "E") with batch normalization

    Args:
        pretrained (bool): If True, returns a model pre-trained on ImageNet
    """
    if pretrained:
        kwargs['init_weights'] = False
    model = VGG(make_layers(cfg['E'], batch_norm=True), **kwargs)
    if pretrained:
        model.load_state_dict(torch.load(os.path.join(models_dir, model_name['vgg19_bn'])))
    return model