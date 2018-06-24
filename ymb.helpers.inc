<?php

/**
 * @file
 */

/**
 * Get all Yandex Money blocks as objects.
 */
function _ymb_get_all_blocks() {
  return db_select('ymb', 'n')
    ->fields('n')
    ->execute();
}

/**
 * Get custom block title from block_custom table.
 */
function _ymb_get_block_title($fieldname, $data) {
  return db_select('block_custom', 'n')
    ->fields('n', ['info'])
    ->condition("n.{$fieldname}", $data)
    ->execute()
    ->fetchField();
}

/**
 * Remove block data from all relative tables.
 */
function _ymb_remove_block_by_bid($bid) {
  db_delete('ymb')
    ->condition('bid', $bid)
    ->execute();
  db_delete('block_custom')
    ->condition('bid', $bid)
    ->execute();
  db_delete('block')
    ->condition('module', 'block')
    ->condition('delta', $bid)
    ->execute();
  db_delete('block_role')
    ->condition('module', 'block')
    ->condition('delta', $bid)
    ->execute();
}

/**
 * Generate template Yandex Money Form with data
 */
function _ymb_generate_template($bid, $receiver, $target, $sum, $url) {
  return "<div class='ymb--form'><form method='POST' action='https://money.yandex.ru/quickpay/confirm.xml'><div class='form-item form-type-textfield form-item-name'><input id='edit-sum--{$bid}' name='sum' value='{$sum}' data-type='number' class='form-text required'></div><div class='form-item form-type-radios form-item-payment-type'><div id='edit-payment-type--{$bid}' class='form-radios'><div class='form-item form-type-radio form-item-payment-type'><input id='edit-payment-type-pc--{$bid}' type='radio' name='paymentType' value='PC' class='form-radio'><label class='option' for='edit-payment-type-pc'>Яндекс.Деньги</label></div><div class='form-item form-type-radio form-item-payment-type'><input id='edit-payment-type-ac--{$bid}' type='radio' name='paymentType' value='AC' class='form-radio'><label class='option' for='edit-payment-type-ac'>Банковская карта</label></div></div></div><div class='form-actions form-wrapper' id='edit-actions--{$bid}'><input id='edit-submit--{$bid}' type='submit' value='Оплатить' class='form-submit'></div><input type='hidden' name='receiver' value='{$receiver}'><input type='hidden' name='targets' value='{$target}'><input type='hidden' name='quickpay-form' value='donate'><input type='hidden' name='successURL' value='{$url}'></form></div>";
}
