import argparse
import os
import os.path as osp
import pickle

from mmcv.runner import get_dist_info, init_dist

from movienet.tools import DistPlaceExtractor

if __name__ == '__main__':
    parser = argparse.ArgumentParser('Detect Person')
    parser.add_argument(
        '--listfile',
        type=str,
        default=None,
        help='the list file of the image names')
    parser.add_argument(
        '--img_prefix', type=str, default=None, help='prefix of the images')
    parser.add_argument(
        '--save_path', type=str, default=None, help='prefix of the images')
    parser.add_argument(
        '--imgs_per_gpu',
        type=int,
        default=1,
        help='the number of images for each gpu, \
            batchsize = num_gpus * imgs_per_gpu')
    parser.add_argument(
        '--workers_per_gpu',
        type=int,
        default=4,
        help='number of works for each gpu')
    parser.add_argument('--local_rank', type=int, default=0)
    parser.add_argument(
        '--weight',
        type=str,
        default=osp.join(os.getcwd(), 'model/resnet50_places365.pth'),
        help='the weight of the model')
    args = parser.parse_args()
    assert osp.isfile(args.weight)

    if 'LOCAL_RANK' not in os.environ:
        os.environ['LOCAL_RANK'] = str(args.local_rank)
    init_dist('pytorch', backend='nccl')

    extractor = DistPlaceExtractor(args.weight)

    assert osp.isfile(args.listfile)
    assert osp.isdir(args.img_prefix)
    imglist = [x.strip() for x in open(args.listfile)]
    results = extractor.batch_extract(
        imglist,
        args.img_prefix,
        imgs_per_gpu=args.imgs_per_gpu,
        workers_per_gpu=args.workers_per_gpu)
    rank, world_size = get_dist_info()
    if rank == 0:
        if args.save_path is not None:
            save_dir = os.path.dirname(args.save_path)
            if not osp.isdir(save_dir):
                os.makedirs(save_dir)
            save_dict = {}
            for imgname, result in zip(imglist, results):
                feature = result.numpy()
                save_dict[imgname] = feature
            with open(args.save_path, 'wb') as f:
                pickle.dump(save_dict, f)
