#ifndef MAXPOOL_LAYER_H
#define MAXPOOL_LAYER_H

#include "cuda.h"
#include "image.h"
#include "layer.h"
#include "network.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef layer maxpool_layer;

image get_maxpool_image(maxpool_layer l);
maxpool_layer make_maxpool_layer(
    int batch, int h, int w, int c, int size, int stride, int padding);
void resize_maxpool_layer(maxpool_layer *l, int w, int h);
void forward_maxpool_layer(const maxpool_layer l, network_state state);
void backward_maxpool_layer(const maxpool_layer l, network_state state);

#ifdef DKGPU
void forward_maxpool_layer_gpu(maxpool_layer l, network_state state);
void backward_maxpool_layer_gpu(maxpool_layer l, network_state state);
#endif

#ifdef __cplusplus
}
#endif

#endif
