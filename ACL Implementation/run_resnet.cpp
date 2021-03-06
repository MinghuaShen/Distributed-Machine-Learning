#include "opWrapper_synthetic.h"
#include "dataLoader.h"
#include <chrono>
#include <arm_compute/runtime/Scheduler.h>

#include "unistd.h"
#include <iostream>
#include <vector>
#include <functional>

using namespace arm_compute;
using namespace utils;
using namespace std;

int main (int argc, char **argv)
{
	
	if(argc != 3)
	{
		std::cout<<"Usage: mpiexec -hostfile [hosts] -np [4] -host [raspberrypi0,raspberrypi1] ./main [numberThread(1)] [numberIteration(100)]"<<std::endl;
		return 0;
	}	
	
	arm_compute::Scheduler::get().set_num_threads(atoi(argv[1]));
	
	//Define Output Tensor
	Tensor * conv1_out = new Tensor();
	Tensor * bn1_out = new Tensor();
	Tensor * pool1_out = opWrapper::configure3DTensor(56,56,64);
	//Layer0
	Tensor * layer0_block0_conv0_out = new Tensor();
	Tensor * layer0_block0_bn0_out = new Tensor();
	Tensor * layer0_block0_conv1_out = new Tensor();
	Tensor * layer0_block0_bn1_out = new Tensor();
	Tensor * layer0_block0_conv2_out = new Tensor();
	Tensor * layer0_block0_bn2_out = new Tensor();
	Tensor * layer0_block0_residual_conv_out = new Tensor();
	Tensor * layer0_block0_residual_bn_out = new Tensor();
	Tensor * layer0_block0_add_out = new Tensor();
	
	Tensor * layer0_block1_conv0_out = new Tensor();
	Tensor * layer0_block1_bn0_out = new Tensor();
	Tensor * layer0_block1_conv1_out = new Tensor();
	Tensor * layer0_block1_bn1_out = new Tensor();
	Tensor * layer0_block1_conv2_out = new Tensor();
	Tensor * layer0_block1_bn2_out = new Tensor();
	Tensor * layer0_block1_add_out = new Tensor();
	
	Tensor * layer0_block2_conv0_out = new Tensor();
	Tensor * layer0_block2_bn0_out = new Tensor();
	Tensor * layer0_block2_conv1_out = new Tensor();
	Tensor * layer0_block2_bn1_out = new Tensor();
	Tensor * layer0_block2_conv2_out = new Tensor();
	Tensor * layer0_block2_bn2_out = new Tensor();
	Tensor * layer0_block2_add_out = new Tensor();
	//Layer1
	Tensor * layer1_block0_conv0_out = new Tensor();
	Tensor * layer1_block0_bn0_out = new Tensor();
	Tensor * layer1_block0_conv1_out = new Tensor();
	Tensor * layer1_block0_bn1_out = new Tensor();
	Tensor * layer1_block0_conv2_out = new Tensor();
	Tensor * layer1_block0_bn2_out = new Tensor();
	Tensor * layer1_block0_residual_conv_out = new Tensor();
	Tensor * layer1_block0_residual_bn_out = new Tensor();
	Tensor * layer1_block0_add_out = new Tensor();
	
	Tensor * layer1_block1_conv0_out = new Tensor();
	Tensor * layer1_block1_bn0_out = new Tensor();
	Tensor * layer1_block1_conv1_out = new Tensor();
	Tensor * layer1_block1_bn1_out = new Tensor();
	Tensor * layer1_block1_conv2_out = new Tensor();
	Tensor * layer1_block1_bn2_out = new Tensor();
	Tensor * layer1_block1_add_out = new Tensor();
	
	Tensor * layer1_block2_conv0_out = new Tensor();
	Tensor * layer1_block2_bn0_out = new Tensor();
	Tensor * layer1_block2_conv1_out = new Tensor();
	Tensor * layer1_block2_bn1_out = new Tensor();
	Tensor * layer1_block2_conv2_out = new Tensor();
	Tensor * layer1_block2_bn2_out = new Tensor();
	Tensor * layer1_block2_add_out = new Tensor();
	
	Tensor * layer1_block3_conv0_out = new Tensor();
	Tensor * layer1_block3_bn0_out = new Tensor();
	Tensor * layer1_block3_conv1_out = new Tensor();
	Tensor * layer1_block3_bn1_out = new Tensor();
	Tensor * layer1_block3_conv2_out = new Tensor();
	Tensor * layer1_block3_bn2_out = new Tensor();
	Tensor * layer1_block3_add_out = new Tensor();
	//Layer2
	Tensor * layer2_block0_conv0_out = new Tensor();
	Tensor * layer2_block0_bn0_out = new Tensor();
	Tensor * layer2_block0_conv1_out = new Tensor();
	Tensor * layer2_block0_bn1_out = new Tensor();
	Tensor * layer2_block0_conv2_out = new Tensor();
	Tensor * layer2_block0_bn2_out = new Tensor();
	Tensor * layer2_block0_residual_conv_out = new Tensor();
	Tensor * layer2_block0_residual_bn_out = new Tensor();
	Tensor * layer2_block0_add_out = new Tensor();
	
	Tensor * layer2_block1_conv0_out = new Tensor();
	Tensor * layer2_block1_bn0_out = new Tensor();
	Tensor * layer2_block1_conv1_out = new Tensor();
	Tensor * layer2_block1_bn1_out = new Tensor();
	Tensor * layer2_block1_conv2_out = new Tensor();
	Tensor * layer2_block1_bn2_out = new Tensor();
	Tensor * layer2_block1_add_out = new Tensor();
	
	Tensor * layer2_block2_conv0_out = new Tensor();
	Tensor * layer2_block2_bn0_out = new Tensor();
	Tensor * layer2_block2_conv1_out = new Tensor();
	Tensor * layer2_block2_bn1_out = new Tensor();
	Tensor * layer2_block2_conv2_out = new Tensor();
	Tensor * layer2_block2_bn2_out = new Tensor();
	Tensor * layer2_block2_add_out = new Tensor();
	
	Tensor * layer2_block3_conv0_out = new Tensor();
	Tensor * layer2_block3_bn0_out = new Tensor();
	Tensor * layer2_block3_conv1_out = new Tensor();
	Tensor * layer2_block3_bn1_out = new Tensor();
	Tensor * layer2_block3_conv2_out = new Tensor();
	Tensor * layer2_block3_bn2_out = new Tensor();
	Tensor * layer2_block3_add_out = new Tensor();
	
	Tensor * layer2_block4_conv0_out = new Tensor();
	Tensor * layer2_block4_bn0_out = new Tensor();
	Tensor * layer2_block4_conv1_out = new Tensor();
	Tensor * layer2_block4_bn1_out = new Tensor();
	Tensor * layer2_block4_conv2_out = new Tensor();
	Tensor * layer2_block4_bn2_out = new Tensor();
	Tensor * layer2_block4_add_out = new Tensor();
	
	Tensor * layer2_block5_conv0_out = new Tensor();
	Tensor * layer2_block5_bn0_out = new Tensor();
	Tensor * layer2_block5_conv1_out = new Tensor();
	Tensor * layer2_block5_bn1_out = new Tensor();
	Tensor * layer2_block5_conv2_out = new Tensor();
	Tensor * layer2_block5_bn2_out = new Tensor();
	Tensor * layer2_block5_add_out = new Tensor();
	//Layer3
	Tensor * layer3_block0_conv0_out = new Tensor();
	Tensor * layer3_block0_bn0_out = new Tensor();
	Tensor * layer3_block0_conv1_out = new Tensor();
	Tensor * layer3_block0_bn1_out = new Tensor();
	Tensor * layer3_block0_conv2_out = new Tensor();
	Tensor * layer3_block0_bn2_out = new Tensor();
	Tensor * layer3_block0_residual_conv_out = new Tensor();
	Tensor * layer3_block0_residual_bn_out = new Tensor();
	Tensor * layer3_block0_add_out = new Tensor();
	
	Tensor * layer3_block1_conv0_out = new Tensor();
	Tensor * layer3_block1_bn0_out = new Tensor();
	Tensor * layer3_block1_conv1_out = new Tensor();
	Tensor * layer3_block1_bn1_out = new Tensor();
	Tensor * layer3_block1_conv2_out = new Tensor();
	Tensor * layer3_block1_bn2_out = new Tensor();
	Tensor * layer3_block1_add_out = new Tensor();
	
	Tensor * layer3_block2_conv0_out = new Tensor();
	Tensor * layer3_block2_bn0_out = new Tensor();
	Tensor * layer3_block2_conv1_out = new Tensor();
	Tensor * layer3_block2_bn1_out = new Tensor();
	Tensor * layer3_block2_conv2_out = new Tensor();
	Tensor * layer3_block2_bn2_out = new Tensor();
	Tensor * layer3_block2_add_out = new Tensor();
	
	Tensor * pool2_out = opWrapper::configure3DTensor(1,1,2048);
	
	Tensor * fc1_out = new Tensor();
	//Define Input Tensor
	pmLoader ppm;
	ppm.open("/root/Project/disInfer/go_kart.ppm");	///home/pi/NeurIoT_mpi
	Tensor * input = new Tensor();
	ppm.init_image(*input, Format::F32);
	
	
	NEConvolutionLayer * conv1 = opWrapper::ConvolutionLayer(input, conv1_out, 2, 3, 7, 7, 3, 64);
	NEBatchNormalizationLayer * bn1 = opWrapper::BNLayer(conv1_out,bn1_out, 64);
	NEPoolingLayer * pool1 = opWrapper::MaxPoolLayer(bn1_out, pool1_out, 3, 2); //pool1_out
	
	//Layer0
	NEConvolutionLayer * 		layer0_block0_conv0 = opWrapper::ConvolutionLayer(pool1_out, layer0_block0_conv0_out, 1, 0, 1, 1, 64, 64);
	NEBatchNormalizationLayer * layer0_block0_bn0 = opWrapper::BNLayer(layer0_block0_conv0_out,layer0_block0_bn0_out, 64);
	NEConvolutionLayer * 		layer0_block0_conv1 = opWrapper::ConvolutionLayer(layer0_block0_bn0_out, layer0_block0_conv1_out, 1, 1, 3, 3, 64, 64);
	NEBatchNormalizationLayer * layer0_block0_bn1 = opWrapper::BNLayer(layer0_block0_conv1_out, layer0_block0_bn1_out, 64);
	NEConvolutionLayer * 		layer0_block0_conv2 = opWrapper::ConvolutionLayer(layer0_block0_bn1_out, layer0_block0_conv2_out, 1, 0, 1, 1, 64, 256);
	NEBatchNormalizationLayer * layer0_block0_bn2 = opWrapper::BNLayer(layer0_block0_conv2_out, layer0_block0_bn2_out, 256);
	NEConvolutionLayer * 		layer0_block0_residual_conv = opWrapper::ConvolutionLayer(pool1_out, layer0_block0_residual_conv_out, 1, 0, 1, 1, 64, 256);
	NEBatchNormalizationLayer * layer0_block0_residual_bn = opWrapper::BNLayer(layer0_block0_residual_conv_out, layer0_block0_residual_bn_out, 256);		
	NEArithmeticAddition * 		layer0_block0_add = opWrapper::ElementAddOp(layer0_block0_bn2_out, layer0_block0_residual_bn_out, layer0_block0_add_out); //layer0_block0_add_out
	
	NEConvolutionLayer * 		layer0_block1_conv0 = opWrapper::ConvolutionLayer(layer0_block0_add_out, layer0_block1_conv0_out, 1, 0, 1, 1, 256, 64);
	NEBatchNormalizationLayer * layer0_block1_bn0 = opWrapper::BNLayer(layer0_block1_conv0_out,layer0_block1_bn0_out, 64);
	NEConvolutionLayer * 		layer0_block1_conv1 = opWrapper::ConvolutionLayer(layer0_block1_bn0_out, layer0_block1_conv1_out, 1, 1, 3, 3, 64, 64);
	NEBatchNormalizationLayer * layer0_block1_bn1 = opWrapper::BNLayer(layer0_block1_conv1_out, layer0_block1_bn1_out, 64);
	NEConvolutionLayer * 		layer0_block1_conv2 = opWrapper::ConvolutionLayer(layer0_block1_bn1_out, layer0_block1_conv2_out, 1, 0, 1, 1, 64, 256);
	NEBatchNormalizationLayer * layer0_block1_bn2 = opWrapper::BNLayer(layer0_block1_conv2_out, layer0_block1_bn2_out, 256);	
	NEArithmeticAddition * 		layer0_block1_add = opWrapper::ElementAddOp(layer0_block0_add_out, layer0_block1_bn2_out, layer0_block1_add_out); //layer0_block0_add_out
	
	NEConvolutionLayer * 		layer0_block2_conv0 = opWrapper::ConvolutionLayer(layer0_block1_add_out, layer0_block2_conv0_out, 1, 0, 1, 1, 256, 64);
	NEBatchNormalizationLayer * layer0_block2_bn0 = opWrapper::BNLayer(layer0_block2_conv0_out,layer0_block2_bn0_out, 64);
	NEConvolutionLayer * 		layer0_block2_conv1 = opWrapper::ConvolutionLayer(layer0_block2_bn0_out, layer0_block2_conv1_out, 1, 1, 3, 3, 64, 64);
	NEBatchNormalizationLayer * layer0_block2_bn1 = opWrapper::BNLayer(layer0_block2_conv1_out, layer0_block2_bn1_out, 64);
	NEConvolutionLayer * 		layer0_block2_conv2 = opWrapper::ConvolutionLayer(layer0_block2_bn1_out, layer0_block2_conv2_out, 1, 0, 1, 1, 64, 256);
	NEBatchNormalizationLayer * layer0_block2_bn2 = opWrapper::BNLayer(layer0_block2_conv2_out, layer0_block2_bn2_out, 256);	
	NEArithmeticAddition * 		layer0_block2_add = opWrapper::ElementAddOp(layer0_block1_add_out, layer0_block2_bn2_out, layer0_block2_add_out); //layer0_block0_add_out
	
	//Layer1
	NEConvolutionLayer * 		layer1_block0_conv0 = opWrapper::ConvolutionLayer(layer0_block2_add_out, layer1_block0_conv0_out, 1, 0, 1, 1, 256, 128);
	NEBatchNormalizationLayer * layer1_block0_bn0 = opWrapper::BNLayer(layer1_block0_conv0_out,layer1_block0_bn0_out, 128);
	NEConvolutionLayer * 		layer1_block0_conv1 = opWrapper::ConvolutionLayer(layer1_block0_bn0_out, layer1_block0_conv1_out, 2, 1, 3, 3, 128, 128);
	NEBatchNormalizationLayer * layer1_block0_bn1 = opWrapper::BNLayer(layer1_block0_conv1_out, layer1_block0_bn1_out, 128);
	NEConvolutionLayer * 		layer1_block0_conv2 = opWrapper::ConvolutionLayer(layer1_block0_bn1_out, layer1_block0_conv2_out, 1, 0, 1, 1, 128, 512);
	NEBatchNormalizationLayer * layer1_block0_bn2 = opWrapper::BNLayer(layer1_block0_conv2_out, layer1_block0_bn2_out, 512);
	NEConvolutionLayer * 		layer1_block0_residual_conv = opWrapper::ConvolutionLayer(layer0_block2_add_out, layer1_block0_residual_conv_out, 2, 0, 1, 1, 256, 512);
	NEBatchNormalizationLayer * layer1_block0_residual_bn = opWrapper::BNLayer(layer1_block0_residual_conv_out, layer1_block0_residual_bn_out, 512);		
	NEArithmeticAddition * 		layer1_block0_add = opWrapper::ElementAddOp(layer1_block0_bn2_out, layer1_block0_residual_bn_out, layer1_block0_add_out); //layer0_block0_add_out
	
	NEConvolutionLayer * 		layer1_block1_conv0 = opWrapper::ConvolutionLayer(layer1_block0_add_out, layer1_block1_conv0_out, 1, 0, 1, 1, 512, 128);
	NEBatchNormalizationLayer * layer1_block1_bn0 = opWrapper::BNLayer(layer1_block1_conv0_out,layer1_block1_bn0_out, 128);	
	NEConvolutionLayer * 		layer1_block1_conv1 = opWrapper::ConvolutionLayer(layer1_block1_bn0_out, layer1_block1_conv1_out, 1, 1, 3, 3, 128, 128);
	NEBatchNormalizationLayer * layer1_block1_bn1 = opWrapper::BNLayer(layer1_block1_conv1_out, layer1_block1_bn1_out, 128);
	NEConvolutionLayer * 		layer1_block1_conv2 = opWrapper::ConvolutionLayer(layer1_block1_bn1_out, layer1_block1_conv2_out, 1, 0, 1, 1, 128, 512);
	NEBatchNormalizationLayer * layer1_block1_bn2 = opWrapper::BNLayer(layer1_block1_conv2_out, layer1_block1_bn2_out, 512);	
	NEArithmeticAddition * 		layer1_block1_add = opWrapper::ElementAddOp(layer1_block0_add_out, layer1_block1_bn2_out, layer1_block1_add_out);
	
	NEConvolutionLayer * 		layer1_block2_conv0 = opWrapper::ConvolutionLayer(layer1_block1_add_out, layer1_block2_conv0_out, 1, 0, 1, 1, 512, 128);
	NEBatchNormalizationLayer * layer1_block2_bn0 = opWrapper::BNLayer(layer1_block2_conv0_out,layer1_block2_bn0_out, 128);
	NEConvolutionLayer * 		layer1_block2_conv1 = opWrapper::ConvolutionLayer(layer1_block2_bn0_out, layer1_block2_conv1_out, 1, 1, 3, 3, 128, 128);
	NEBatchNormalizationLayer * layer1_block2_bn1 = opWrapper::BNLayer(layer1_block2_conv1_out, layer1_block2_bn1_out, 128);
	NEConvolutionLayer * 		layer1_block2_conv2 = opWrapper::ConvolutionLayer(layer1_block2_bn1_out, layer1_block2_conv2_out, 1, 0, 1, 1, 128, 512);
	NEBatchNormalizationLayer * layer1_block2_bn2 = opWrapper::BNLayer(layer1_block2_conv2_out, layer1_block2_bn2_out, 512);	
	NEArithmeticAddition * 		layer1_block2_add = opWrapper::ElementAddOp(layer1_block1_add_out, layer1_block2_bn2_out, layer1_block2_add_out); //layer0_block0_add_out
	
	NEConvolutionLayer * 		layer1_block3_conv0 = opWrapper::ConvolutionLayer(layer1_block2_add_out, layer1_block3_conv0_out, 1, 0, 1, 1, 512, 128);
	NEBatchNormalizationLayer * layer1_block3_bn0 = opWrapper::BNLayer(layer1_block3_conv0_out,layer1_block3_bn0_out, 128);
	NEConvolutionLayer * 		layer1_block3_conv1 = opWrapper::ConvolutionLayer(layer1_block3_bn0_out, layer1_block3_conv1_out, 1, 1, 3, 3, 128, 128);
	NEBatchNormalizationLayer * layer1_block3_bn1 = opWrapper::BNLayer(layer1_block3_conv1_out, layer1_block3_bn1_out, 128);
	NEConvolutionLayer * 		layer1_block3_conv2 = opWrapper::ConvolutionLayer(layer1_block3_bn1_out, layer1_block3_conv2_out, 1, 0, 1, 1, 128, 512);
	NEBatchNormalizationLayer * layer1_block3_bn2 = opWrapper::BNLayer(layer1_block3_conv2_out, layer1_block3_bn2_out, 512);	
	NEArithmeticAddition * 		layer1_block3_add = opWrapper::ElementAddOp(layer1_block2_add_out, layer1_block3_bn2_out, layer1_block3_add_out); //layer0_block0_add_out	
	//Layer2
	NEConvolutionLayer * 		layer2_block0_conv0 = opWrapper::ConvolutionLayer(layer1_block3_add_out, layer2_block0_conv0_out, 1, 0, 1, 1, 512, 256);
	NEBatchNormalizationLayer * layer2_block0_bn0 = opWrapper::BNLayer(layer2_block0_conv0_out,layer2_block0_bn0_out, 256);
	NEConvolutionLayer * 		layer2_block0_conv1 = opWrapper::ConvolutionLayer(layer2_block0_bn0_out, layer2_block0_conv1_out, 2, 1, 3, 3, 256, 256);
	NEBatchNormalizationLayer * layer2_block0_bn1 = opWrapper::BNLayer(layer2_block0_conv1_out, layer2_block0_bn1_out, 256);
	NEConvolutionLayer * 		layer2_block0_conv2 = opWrapper::ConvolutionLayer(layer2_block0_bn1_out, layer2_block0_conv2_out, 1, 0, 1, 1, 256, 1024);
	NEBatchNormalizationLayer * layer2_block0_bn2 = opWrapper::BNLayer(layer2_block0_conv2_out, layer2_block0_bn2_out, 1024);
	NEConvolutionLayer * 		layer2_block0_residual_conv = opWrapper::ConvolutionLayer(layer1_block3_add_out, layer2_block0_residual_conv_out, 2, 0, 1, 1, 512, 1024);
	NEBatchNormalizationLayer * layer2_block0_residual_bn = opWrapper::BNLayer(layer2_block0_residual_conv_out, layer2_block0_residual_bn_out, 1024);		
	NEArithmeticAddition * 		layer2_block0_add = opWrapper::ElementAddOp(layer2_block0_bn2_out, layer2_block0_residual_bn_out, layer2_block0_add_out); //layer0_block0_add_out
	
	NEConvolutionLayer * 		layer2_block1_conv0 = opWrapper::ConvolutionLayer(layer2_block0_add_out, layer2_block1_conv0_out, 1, 0, 1, 1, 1024, 256);
	NEBatchNormalizationLayer * layer2_block1_bn0 = opWrapper::BNLayer(layer2_block1_conv0_out,layer2_block1_bn0_out, 256);
	NEConvolutionLayer * 		layer2_block1_conv1 = opWrapper::ConvolutionLayer(layer2_block1_bn0_out, layer2_block1_conv1_out, 1, 1, 3, 3, 256, 256);
	NEBatchNormalizationLayer * layer2_block1_bn1 = opWrapper::BNLayer(layer2_block1_conv1_out, layer2_block1_bn1_out, 256);
	NEConvolutionLayer * 		layer2_block1_conv2 = opWrapper::ConvolutionLayer(layer2_block1_bn1_out, layer2_block1_conv2_out, 1, 0, 1, 1, 256, 1024);
	NEBatchNormalizationLayer * layer2_block1_bn2 = opWrapper::BNLayer(layer2_block1_conv2_out, layer2_block1_bn2_out, 1024);	
	NEArithmeticAddition * 		layer2_block1_add = opWrapper::ElementAddOp(layer2_block0_add_out, layer2_block1_bn2_out, layer2_block1_add_out);
	
	NEConvolutionLayer * 		layer2_block2_conv0 = opWrapper::ConvolutionLayer(layer2_block1_add_out, layer2_block2_conv0_out, 1, 0, 1, 1, 1024, 256);
	NEBatchNormalizationLayer * layer2_block2_bn0 = opWrapper::BNLayer(layer2_block2_conv0_out,layer2_block2_bn0_out, 256);
	NEConvolutionLayer * 		layer2_block2_conv1 = opWrapper::ConvolutionLayer(layer2_block2_bn0_out, layer2_block2_conv1_out, 1, 1, 3, 3, 256, 256);
	NEBatchNormalizationLayer * layer2_block2_bn1 = opWrapper::BNLayer(layer2_block2_conv1_out, layer2_block2_bn1_out, 256);
	NEConvolutionLayer * 		layer2_block2_conv2 = opWrapper::ConvolutionLayer(layer2_block2_bn1_out, layer2_block2_conv2_out, 1, 0, 1, 1, 256, 1024);
	NEBatchNormalizationLayer * layer2_block2_bn2 = opWrapper::BNLayer(layer2_block2_conv2_out, layer2_block2_bn2_out, 1024);	
	NEArithmeticAddition * 		layer2_block2_add = opWrapper::ElementAddOp(layer2_block1_add_out, layer2_block2_bn2_out, layer2_block2_add_out);
	
	NEConvolutionLayer * 		layer2_block3_conv0 = opWrapper::ConvolutionLayer(layer2_block2_add_out, layer2_block3_conv0_out, 1, 0, 1, 1, 1024, 256);
	NEBatchNormalizationLayer * layer2_block3_bn0 = opWrapper::BNLayer(layer2_block3_conv0_out,layer2_block3_bn0_out, 256);
	NEConvolutionLayer * 		layer2_block3_conv1 = opWrapper::ConvolutionLayer(layer2_block3_bn0_out, layer2_block3_conv1_out, 1, 1, 3, 3, 256, 256);
	NEBatchNormalizationLayer * layer2_block3_bn1 = opWrapper::BNLayer(layer2_block3_conv1_out, layer2_block3_bn1_out, 256);
	NEConvolutionLayer * 		layer2_block3_conv2 = opWrapper::ConvolutionLayer(layer2_block3_bn1_out, layer2_block3_conv2_out, 1, 0, 1, 1, 256, 1024);
	NEBatchNormalizationLayer * layer2_block3_bn2 = opWrapper::BNLayer(layer2_block3_conv2_out, layer2_block3_bn2_out, 1024);	
	NEArithmeticAddition * 		layer2_block3_add = opWrapper::ElementAddOp(layer2_block2_add_out, layer2_block3_bn2_out, layer2_block3_add_out);
	
	NEConvolutionLayer * 		layer2_block4_conv0 = opWrapper::ConvolutionLayer(layer2_block3_add_out, layer2_block4_conv0_out, 1, 0, 1, 1, 1024, 256);
	NEBatchNormalizationLayer * layer2_block4_bn0 = opWrapper::BNLayer(layer2_block4_conv0_out,layer2_block4_bn0_out, 256);
	NEConvolutionLayer * 		layer2_block4_conv1 = opWrapper::ConvolutionLayer(layer2_block4_bn0_out, layer2_block4_conv1_out, 1, 1, 3, 3, 256, 256);
	NEBatchNormalizationLayer * layer2_block4_bn1 = opWrapper::BNLayer(layer2_block4_conv1_out, layer2_block4_bn1_out, 256);
	NEConvolutionLayer * 		layer2_block4_conv2 = opWrapper::ConvolutionLayer(layer2_block4_bn1_out, layer2_block4_conv2_out, 1, 0, 1, 1, 256, 1024);
	NEBatchNormalizationLayer * layer2_block4_bn2 = opWrapper::BNLayer(layer2_block4_conv2_out, layer2_block4_bn2_out, 1024);	
	NEArithmeticAddition * 		layer2_block4_add = opWrapper::ElementAddOp(layer2_block3_add_out, layer2_block4_bn2_out, layer2_block4_add_out);
	
	NEConvolutionLayer * 		layer2_block5_conv0 = opWrapper::ConvolutionLayer(layer2_block4_add_out, layer2_block5_conv0_out, 1, 0, 1, 1, 1024, 256);
	NEBatchNormalizationLayer * layer2_block5_bn0 = opWrapper::BNLayer(layer2_block5_conv0_out,layer2_block5_bn0_out, 256);
	NEConvolutionLayer * 		layer2_block5_conv1 = opWrapper::ConvolutionLayer(layer2_block5_bn0_out, layer2_block5_conv1_out, 1, 1, 3, 3, 256, 256);
	NEBatchNormalizationLayer * layer2_block5_bn1 = opWrapper::BNLayer(layer2_block5_conv1_out, layer2_block5_bn1_out, 256);
	NEConvolutionLayer * 		layer2_block5_conv2 = opWrapper::ConvolutionLayer(layer2_block5_bn1_out, layer2_block5_conv2_out, 1, 0, 1, 1, 256, 1024);
	NEBatchNormalizationLayer * layer2_block5_bn2 = opWrapper::BNLayer(layer2_block5_conv2_out, layer2_block5_bn2_out, 1024);	
	NEArithmeticAddition * 		layer2_block5_add = opWrapper::ElementAddOp(layer2_block4_add_out, layer2_block5_bn2_out, layer2_block5_add_out);
	//Layer3
	
	NEConvolutionLayer * 		layer3_block0_conv0 = opWrapper::ConvolutionLayer(layer2_block5_add_out, layer3_block0_conv0_out, 1, 0, 1, 1, 1024, 512);
	NEBatchNormalizationLayer * layer3_block0_bn0 = opWrapper::BNLayer(layer3_block0_conv0_out,layer3_block0_bn0_out, 512);
	NEConvolutionLayer * 		layer3_block0_conv1 = opWrapper::ConvolutionLayer(layer3_block0_bn0_out, layer3_block0_conv1_out, 2, 1, 3, 3, 512, 512);
	NEBatchNormalizationLayer * layer3_block0_bn1 = opWrapper::BNLayer(layer3_block0_conv1_out, layer3_block0_bn1_out, 512);
	NEConvolutionLayer * 		layer3_block0_conv2 = opWrapper::ConvolutionLayer(layer3_block0_bn1_out, layer3_block0_conv2_out, 1, 0, 1, 1, 512, 2048);
	NEBatchNormalizationLayer * layer3_block0_bn2 = opWrapper::BNLayer(layer3_block0_conv2_out, layer3_block0_bn2_out, 2048);
	NEConvolutionLayer * 		layer3_block0_residual_conv = opWrapper::ConvolutionLayer(layer2_block5_add_out, layer3_block0_residual_conv_out, 2, 0, 1, 1, 1024, 2048);
	NEBatchNormalizationLayer * layer3_block0_residual_bn = opWrapper::BNLayer(layer3_block0_residual_conv_out, layer3_block0_residual_bn_out, 2048);		
	NEArithmeticAddition * 		layer3_block0_add = opWrapper::ElementAddOp(layer3_block0_bn2_out, layer3_block0_residual_bn_out, layer3_block0_add_out); //layer0_block0_add_out
	
	NEConvolutionLayer * 		layer3_block1_conv0 = opWrapper::ConvolutionLayer(layer3_block0_add_out, layer3_block1_conv0_out, 1, 0, 1, 1, 2048, 512);
	NEBatchNormalizationLayer * layer3_block1_bn0 = opWrapper::BNLayer(layer3_block1_conv0_out,layer3_block1_bn0_out, 512);
	NEConvolutionLayer * 		layer3_block1_conv1 = opWrapper::ConvolutionLayer(layer3_block1_bn0_out, layer3_block1_conv1_out, 1, 1, 3, 3, 512, 512);
	NEBatchNormalizationLayer * layer3_block1_bn1 = opWrapper::BNLayer(layer3_block1_conv1_out, layer3_block1_bn1_out, 512);
	NEConvolutionLayer * 		layer3_block1_conv2 = opWrapper::ConvolutionLayer(layer3_block1_bn1_out, layer3_block1_conv2_out, 1, 0, 1, 1, 512, 2048);
	NEBatchNormalizationLayer * layer3_block1_bn2 = opWrapper::BNLayer(layer3_block1_conv2_out, layer3_block1_bn2_out, 2048);	
	NEArithmeticAddition * 		layer3_block1_add = opWrapper::ElementAddOp(layer3_block0_add_out, layer3_block1_bn2_out, layer3_block1_add_out);
	
	NEConvolutionLayer * 		layer3_block2_conv0 = opWrapper::ConvolutionLayer(layer3_block1_add_out, layer3_block2_conv0_out, 1, 0, 1, 1, 2048, 512);
	NEBatchNormalizationLayer * layer3_block2_bn0 = opWrapper::BNLayer(layer3_block2_conv0_out,layer3_block2_bn0_out, 512);
	NEConvolutionLayer * 		layer3_block2_conv1 = opWrapper::ConvolutionLayer(layer3_block2_bn0_out, layer3_block2_conv1_out, 1, 1, 3, 3, 512, 512);
	NEBatchNormalizationLayer * layer3_block2_bn1 = opWrapper::BNLayer(layer3_block2_conv1_out, layer3_block2_bn1_out, 512);
	NEConvolutionLayer * 		layer3_block2_conv2 = opWrapper::ConvolutionLayer(layer3_block2_bn1_out, layer3_block2_conv2_out, 1, 0, 1, 1, 512, 2048);
	NEBatchNormalizationLayer * layer3_block2_bn2 = opWrapper::BNLayer(layer3_block2_conv2_out, layer3_block2_bn2_out, 2048);	
	NEArithmeticAddition * 		layer3_block2_add = opWrapper::ElementAddOp(layer3_block1_add_out, layer3_block1_bn2_out, layer3_block2_add_out);
	
	NEPoolingLayer * 			pool2 = opWrapper::MaxPoolLayer(layer3_block2_add_out, pool2_out, 7, 1); //pool1_out
	
	NEFullyConnectedLayer *		fcl = opWrapper::FullyConnectedLayer(pool2_out, fc1_out, 2048, 1000);
	
	
	//Construct Function Array	
	
	vector<std::function<void()>> m_vecFuc;
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,bn1));
	m_vecFuc.push_back(std::bind(&NEPoolingLayer::run,pool1));
	//Layer0
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer0_block0_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer0_block0_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer0_block0_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer0_block0_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer0_block0_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer0_block0_bn2));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer0_block0_residual_conv));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer0_block0_residual_bn));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer0_block0_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer0_block1_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer0_block1_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer0_block1_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer0_block1_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer0_block1_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer0_block1_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer0_block1_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer0_block2_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer0_block2_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer0_block2_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer0_block2_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer0_block2_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer0_block2_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer0_block2_add));
	
	//Layer1
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block0_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block0_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block0_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block0_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block0_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block0_bn2));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block0_residual_conv));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block0_residual_bn));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer1_block0_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block1_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block1_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block1_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block1_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block1_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block1_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer1_block1_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block2_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block2_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block2_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block2_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block2_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block2_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer1_block2_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block3_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block3_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block3_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block3_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer1_block3_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer1_block3_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer1_block3_add));
	
	//Layer2
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block0_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block0_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block0_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block0_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block0_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block0_bn2));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block0_residual_conv));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block0_residual_bn));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer2_block0_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block1_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block1_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block1_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block1_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block1_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block1_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer2_block1_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block2_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block2_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block2_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block2_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block2_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block2_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer2_block2_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block3_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block3_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block3_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block3_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block3_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block3_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer2_block3_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block4_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block4_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block4_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block4_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block4_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block4_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer2_block4_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block5_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block5_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block5_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block5_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer2_block5_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer2_block5_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer2_block5_add));
	
	//Layer3
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer3_block0_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer3_block0_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer3_block0_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer3_block0_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer3_block0_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer3_block0_bn2));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer3_block0_residual_conv));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer3_block0_residual_bn));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer3_block0_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer3_block1_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer3_block1_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer3_block1_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer3_block1_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer3_block1_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer3_block1_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer3_block1_add));
	
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer3_block2_conv0));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer3_block2_bn0));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer3_block2_conv1));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer3_block2_bn1));
	m_vecFuc.push_back(std::bind(&NEConvolutionLayer::run,layer3_block2_conv2));
	m_vecFuc.push_back(std::bind(&NEBatchNormalizationLayer::run,layer3_block2_bn2));
	m_vecFuc.push_back(std::bind(&NEArithmeticAddition::run,layer3_block2_add));
	
	
	m_vecFuc.push_back(std::bind(&NEPoolingLayer::run,pool2));
	m_vecFuc.push_back(std::bind(&NEFullyConnectedLayer::run,fcl));
	//Run
	input->allocator()->allocate();
	if(ppm.is_open())
	{
		ppm.fill_image(*input);
	}	
	ppm.close(); 
	
	int iters = 0;
	int layer_num = (int)m_vecFuc.size();
	cout<<"The number of layers is: "<< layer_num <<endl;
	
	auto beginTime = std::chrono::steady_clock::now();
	while(iters<atoi(argv[2]))
	{
		
		for(int i = 0; i<layer_num; i++){
			m_vecFuc[i]();
			//cout<<"Running Layer:" <<i<<endl;
		}		
		iters++;
	}
	auto endTime = std::chrono::steady_clock::now();
	auto elapsedTime= std::chrono::duration<double,std::milli>(endTime - beginTime);
    std::cout << "elapsed time is " << elapsedTime.count() << " ms" << std::endl;
	
	return 0;
}
