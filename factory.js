import {
  server_url
} from '../comm/script/config'
const JSONstring = JSON.stringify('')
const aliyun_store =
  server_url == 'https://api.momowoo.com/' ? 'log-app' : 'log-app-test';
(function (wx) {
  function AliLogTracker(obj, head_obj, head_object) {
    aliyun_store
    this.uri_ =
      'https://' +
      aliyun_store +
      '.' +
      'cn-hangzhou.log.aliyuncs.com' +
      '/logstores/' +
      'store' +
      '/track?APIVersion=0.6.0'
    this.httpRequest_ = wx.request
    this.params_ = []
    if (obj) {
      if (typeof obj == 'object') {
        for (var k in obj) {
          this.push(k, obj[k])
        }
      }
      if (head_obj) {
        for (var h in head_obj.data) {
          this.push(head_obj.head + '_' + h, head_obj.data[h], head_obj.head)
        }
      }
      if (head_object) {
        for (var h in head_object.data) {
          this.push(
            head_object.head + '_' + h,
            head_object.data[h],
            head_object.head
          )
        }
      }
      this.time = setTimeout(() => {
        this.logger()
      }, 1000)
    }
  }
  
  AliLogTracker.prototype = {
    push: function (key, value, head) {
      if (!key || (!value && value != 0) || value == JSONstring) {
        return false
      } else {
        if (key == 'object') {
          for (var prop in value) {
            if (head) {
              this.params_.push(head + '_' + this.toLine(prop))
            } else {
              this.params_.push(this.toLine(prop))
            }
            if (typeof value[prop] == 'object') {
              this.params_.push(JSON.stringify(value[prop]))
            } else {
              this.params_.push(value[prop])
            }
          }
        } else {
          if (value) {
            this.params_.push(this.toLine(key))
            this.params_.push(value)
          }
        }
      }
    },
    toLine: function (name) {
      return name.replace(/([A-Z])/g, '_$1').toLowerCase()
    },
    send: function (arr) {
      var url = this.uri_
      var k = 0
      while (arr.length > 0) {
        if (k % 2 == 0) {
          url += '&' + encodeURIComponent(arr.shift())
        } else {
          url += '=' + encodeURIComponent(arr.shift())
        }
        ++k
      }
      try {
        wx.request({
          url: url, //仅为示例，并非真实的接口地址
          data: null,
          method: 'GET',
          success: function (res) {
            if (res.data.error) {} else {}
          },
          fail: function (reponse) {}
        })
      } catch (ex) {

      }
    },
    logger: function () {
      var list = []
      var arr_list = []
      var login = wx.getStorageSync('login')
      var company_id = wx.getStorageSync('company_id')
      var open_id = wx.getStorageSync('open_id')
      var distance = wx.getStorageSync('distance')
      var shop_id = wx.getStorageSync('shop_id')
      var sales_id = wx.getStorageSync('sales_id')
      var lastest_send_tracker = wx.getStorageSync('lastest_send_tracker')

      if (open_id) {
        //通用
        this.push('__topic__', 'mini')
        this.push('client_type', 'mini')
        this.push('open_id', open_id)
        if (sales_id) {
          this.push('sales_id', sales_id)
        }
        if (login) {
          delete login.token
          delete login.refresh_expired_at
          delete login.expired_at
          delete login.open_id
          delete login.company_id
          this.push('object', login)
        }
        if (company_id) {
          this.push('company_id', company_id)
        }
        if (distance) {
          this.push('longitude', distance.user_longitude)
          this.push('latitude', distance.user_latitude)
          this.push('distance_shop_id', distance.shop_id)
        }
        if (shop_id) {
          this.push('shop_id', shop_id)
        }
        if (lastest_send_tracker) {
          list = JSON.parse(lastest_send_tracker)
          for (var i = 0; i < list.length; i++) {
            arr_list = this.params_.concat(list[i])
            this.send(arr_list)
          }
          wx.removeStorageSync('lastest_send_tracker')
        }
        this.send(this.params_)
      } else {
        if (lastest_send_tracker) {
          list = JSON.parse(lastest_send_tracker)
        } else {
          list = []
        }
        list.push(this.params_)
        wx.setStorageSync('lastest_send_tracker', JSON.stringify(list))
      }
    }
  }
  wx.Tracker = AliLogTracker
})(wx)